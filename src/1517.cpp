#include <bits/stdc++.h>


namespace task1517
{
    struct SuffixAutomat
    {
        struct State
        {
            int link, len;
            std::vector <int> next;

            State()
            {
                len = 0;
                link = -1;
                next.resize(26, -1);
            }

            inline void add(char c, int v)
            {
                next[c - 'A'] = v;
            }

            inline int get(char c) const
            {
                return next[c - 'A'];
            }
        };


        int last;
        std::vector <State> st;

        SuffixAutomat()
        {
            init();
        }

        SuffixAutomat(const std::string & s)
        {
            init();
            for (int i = 0; i < (int)s.size(); ++i)
            {
                add(s[i]);
            }
        }

        inline void init()
        {
            last = 0;
            st.resize(1, State());
        }

        inline void add(char c)
        {
            int index = (int)st.size();
            st.push_back(State());
            st[index].len = st[last].len + 1;

            int p = last;
            while (p != -1 && st[p].get(c) == -1)
            {
                st[p].add(c, index);
                p = st[p].link;
            }

            if (p == -1)
            {
                st[index].link = 0;
            }
            else
            {
                int q = st[p].get(c);
                if (st[q].len == st[p].len + 1)
                {
                    st[index].link = q;
                }
                else
                {
                    int cl = (int)st.size();
                    st.push_back(State());
                    st[cl].len = st[p].len + 1;
                    st[cl].link = st[q].link;
                    st[cl].next = st[q].next;
                    while (p != -1 && st[p].get(c) == q)
                    {
                        st[p].add(c, cl);
                        p = st[p].link;
                    }
                    st[q].link = st[index].link = cl;
                }
            }
            last = index;
        }
    };


    int solve(std::istream & in, std::ostream & out)
    {
        int n;
        std::string s, t;
        in >> n >> s >> t;
        SuffixAutomat sa(s);
        int p = 0, len = 0, bestlen = 0, bestpos = 0;
        for (int i = 0; i < (int)t.size(); ++i)
        {
            char c = t[i];
            while (p && sa.st[p].get(c) == -1)
            {
                p = sa.st[p].link;
                len = sa.st[p].len;
            }
            if (sa.st[p].get(c) != -1)
            {
                p = sa.st[p].get(c);
                ++len;
            }
            if (len > bestlen)
            {
                bestlen = len;
                bestpos = i - len + 1;
            }
        }
        out << t.substr(bestpos, bestlen) << std::endl;
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
        (void)task1517::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1517.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1517.out");
        int status = task1517::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
