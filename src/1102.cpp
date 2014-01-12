#include <bits/stdc++.h>


namespace task1102
{
    struct Symbols
    {
        enum type
        {
            N = 0,
            E = 1,
            ON = 2,
            IN = 4,
            OUT = 8,
            PUT = 16,
        } Value;
    };


    int solve(std::istream & in, std::ostream & out)
    {
        std::string w[] = {
                              "one",
                              "puton",
                              "input",
                              "output",
                              "in",
                              "out",
                          };
        int n;
        in >> n;
        for (int i = 0; i < n; ++i)
        {
            std::string s;
            in >> s;
            s += "xx";
            std::vector <char> u;
            u.reserve(s.size());
            std::string ans = "YES\n";
            for (int k = 0; k < (int)s.size() - 2;)
            {
                if (s[k] == 'e')
                {
                    u.push_back((char)Symbols::E);
                    ++k;
                }
                else if (s[k] == 'o' && s[k + 1] == 'n')
                {
                    u.push_back((char)Symbols::ON);
                    ++++k;
                }
                else if (s[k] == 'i' && s[k + 1] == 'n')
                {
                    u.push_back((char)Symbols::IN);
                    ++++k;
                }
                else if (s[k] == 'o' && s[k + 1] == 'u' && s[k + 2] == 't')
                {
                    u.push_back((char)Symbols::OUT);
                    ++++++k;
                }
                else if (s[k] == 'p' && s[k + 1] == 'u' && s[k + 2] == 't')
                {
                    u.push_back((char)Symbols::PUT);
                    ++++++k;
                }
                else
                {
                    ans = "NO\n";
                    break;
                }
            }

            if (ans[0] != 'Y')
            {
                out << ans;
                continue;
            }

            short f[] = {
                            (2 << 5) + 1,
                            (16 << 5) + 2,
                            (4 << 5) + 16,
                            (8 << 5) + 16,
                            4,
                            8
                        };
            int unused = 0;
            std::vector <char> used(u.size(), 1);

            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < (int)u.size() - 1; ++k)
                {
                    short t = ((short)u[k] << 5) + u[k+1];
                    if (t == f[j] && used[k] && used[k+1])
                    {
                        used[k] = used[k+1] = 0;
                        unused += 2;
                    }
                }
            }
            for (int k = 0; k < (int)u.size(); ++k)
            {
                if (used[k] && (u[k] == f[4] || u[k] == f[5]))
                {
                    used[k] = 0;
                    ++unused;
                }
            }

            if (unused < (int)u.size())
            {
                ans = "NO\n";
            }

            out << ans;
        }
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
        (void)task1102::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1102.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1102.out");
        int status = task1102::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
