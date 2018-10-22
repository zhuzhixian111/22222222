#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using int_t = int;
using std::cin;
using std::cout;
using std::endl;
const int_t INF = 0x7fffffff;
const int_t LARGE = 500000;
//并查集中的一个元素
struct State
{
    int_t parent = -1;
    int_t dis = INF;
    int_t size;
    State(int_t p = -1, int_t d = INF, int_t size = 1)
    {
        this->parent = p;
        this->dis = d;
        this->size = size;
    }
    State generate(int_t parent)
    {
        State result = *this;
        result.parent = parent;
        return result;
    }
    State byDis(int_t dis, int_t size)
    {
        State result = *this;
        result.dis = dis;
        result.size = size;
        return result;
    }
};
//可持久化数组的实现
struct PersistableArray
{
    struct Pair
    {
        int_t version;
        State val;
        Pair(int_t v, const State &s)
        {
            version = v;
            val = s;
        }
        operator int_t()
        {
            return version;
        }
        bool operator<(const Pair &x)
        {
            return version < x.version;
        }
    };
    std::vector<Pair> items[LARGE + 1];
    int_t n;
    int_t version_n = 0;
    PersistableArray(int_t n, State *states)
    {
        this->n = n;
        for (int_t i = 1; i <= n; i++)
        {
            items[i].push_back(Pair{0, states[i]});
        }
    }
    int_t modify(int_t pos, const State &val)
    {
        items[pos].push_back(Pair{++version_n, val});
        return version_n;
    }
    State &query(int_t pos, int_t ver)
    {
        if (ver > items[pos].back())
            return items[pos].back().val;
        auto itr = std::lower_bound(items[pos].begin(), items[pos].end(), ver);
        while (*itr > ver)
            itr--;
        return (*itr).val;
    }
};
//在数组arr中，基于版本ver查询x对应的状态
State query(PersistableArray *arr, int_t ver, int_t x)
{
    State curr;
    while ((curr = arr->query(x, ver)).parent != x)
    {
        x = curr.parent;
    }
    return curr;
}
//合并基于base版本的v1和v2集合，返回新版本
int_t merge(PersistableArray *arr, int_t base, int_t v1, int_t v2)
{
    
    State s1 = query(arr, base, v1);
    State s2 = query(arr, base, v2);
    if(s1.parent==s2.parent) return base;
    if (s1.size > s2.size)
    {
        std::swap(s1, s2);
    }
    arr->modify(s1.parent, s1.generate(s2.parent));
    return arr->modify(s2.parent, s2.byDis(std::min(s1.dis, s2.dis), std::max(s1.size + 1, s2.size)));
}

struct Edge
{
    int_t from;
    int_t to;
    int_t weight;
    int_t altitude;
    int_t version = -1;
    Edge(int_t from, int_t to, int_t weight, int_t altitude)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->altitude = altitude;
    }

    operator int_t()
    {
        return altitude;
    }

    bool operator>(const Edge &edge)
    {
        return altitude > edge.altitude;
    }
};

struct Processor
{
    std::vector<Edge> edges;
    // std::vector<int_t> numbers;
    std::vector<Edge> graph[LARGE + 1];
    int n, m;
    int q, k, s;
    int_t dis[LARGE + 1];
    bool visited[LARGE + 1];
    PersistableArray *arr;

    void process()
    {

        scanf("%d%d", &n, &m);

        edges.push_back(Edge(-1, -1, -1, INF));
        for (int_t i = 1; i <= m; i++)
        {
            int from, to, weight, alt;
            scanf("%d%d%d%d", &from, &to, &weight, &alt);
            edges.push_back(Edge(from, to, weight, alt));
            // numbers.push_back(alt);
            graph[from].push_back(Edge(from, to, weight, alt));
            graph[to].push_back(Edge(to, from, weight, alt));
        }
        std::sort(edges.begin(), edges.end(), [&](const Edge &a, const Edge &b) -> bool { return a.altitude < b.altitude; });
        Dijkstra();
        scanf("%d%d%d", &q, &k, &s);
        if (q == 0)
            return;
        static State inits[LARGE + 1];
        for (int_t i = 1; i <= n; i++)
        {
            inits[i] = State(i, dis[i]);
        }
        arr = new PersistableArray(n, inits);
        edges.back().version = 0;
        for (int_t i = edges.size() - 1; i >= 0; i--)
        {
            auto &edge = edges[i];
            if (i != edges.size() - 1)
                edge.version = merge(arr, edges[i + 1].version, edge.from, edge.to);
        }

        int_t lastans = 0;
        for (int_t i = 1; i <= q; i++)
        {
            int vertex, alt;
            scanf("%d%d", &vertex, &alt);
            vertex = (vertex + k * lastans - 1) % n + 1;
            alt = (alt + lastans * k) % (s + 1);
            auto &edge = (*std::upper_bound(edges.begin(), edges.end(), alt));
            int_t result = query(arr, edge.version, vertex).dis;
            printf("%d\n", (int)result);
            lastans = result;
            // if (i % 800 == 0)
            //     cout << "query " << i << endl;
        }
    }
    void Dijkstra()
    {
        std::fill(dis + 1, dis + 1 + n, INF);
        std::fill(visited + 1, visited + 1 + n, false);
        dis[1] = 0;
        struct Pair
        {
            int_t vertex;
            int_t dis;

            Pair(int_t v, int_t d)
            {
                vertex = v;
                dis = d;
            }
        };
        const auto comp = [&](const Pair &a, const Pair &b) -> bool {
            return a.dis > b.dis;
        };
        std::priority_queue<Pair, std::vector<Pair>, decltype(comp)> heap(comp);
        heap.push(Pair{1, 0});
        while (heap.empty() == false)
        {
            auto front = heap.top();
            heap.pop();
            if (visited[front.vertex])
                continue;
            visited[front.vertex] = true;
            for (Edge &edge : graph[front.vertex])
            {
                if (dis[edge.to] > dis[edge.from] + edge.weight)
                {
                    dis[edge.to] = dis[edge.from] + edge.weight;
                    heap.push(Pair{edge.to, dis[edge.to]});
                }
            }
        }
    }
};

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        auto p = new Processor;
        p->process();
        delete p;
    }
    return 0;
}
