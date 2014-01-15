#include <bits/stdc++.h>


namespace task1590
{
    struct State
    {
        int len, link;
        std::map <char, int> next;

        State() : len(0), link(-1)
        {
        }
    };


    struct SAutomat
    {
        std::vector <State> states;
        std::vector <int> dp;
        int last;

        SAutomat() : last(0)
        {
            add_state();
        }

        void add_state()
        {
            states.push_back(State());
            dp.push_back(-1);
        }

        void add(char c)
        {
            int cur = (int)states.size();
            add_state();
            states[cur].len = states[last].len + 1;
            int p = last;
            while (p != -1 && states[p].next.count(c) == 0)
            {
                states[p].next[c] = cur;
                p = states[p].link;
            }
            if (p == -1)
            {
                states[cur].link = 0;
            }
            else
            {
                int q = states[p].next[c];
                if (states[p].len == states[q].len - 1)
                {
                    states[cur].link = q;
                }
                else
                {
                    int clone = (int)states.size();
                    add_state();
                    states[clone].len = states[p].len + 1;
                    states[clone].link = states[q].link;
                    states[clone].next = states[q].next;
                    while (p != -1 && states[p].next[c] == q)
                    {
                        states[p].next[c] = clone;
                        p = states[p].link;
                    }
                    states[q].link = states[cur].link = clone;
                }
            }
            last = cur;
        }

        int ways(int v)
        {
            if (dp[v] != -1)
            {
                return dp[v];
            }
            int res = 1;
            std::map <char, int> :: const_iterator it = states[v].next.begin();
            while (it != states[v].next.end())
            {
                res += ways(it->second);
                ++it;
            }
            return dp[v] = res;
        }
    };


    int solve(std::istream & in, std::ostream & out)
    {
        SAutomat sa;
        char c;
        while (in >> c)
        {
            sa.add(c);
        }
        out << sa.ways(0) - 1 << std::endl;
        return 0;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    srand((unsigned)time(0));

#ifdef ONLINE_JUDGE
    do
    {
        (void)task1590::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1590.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1590.out");
        int status = task1590::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
