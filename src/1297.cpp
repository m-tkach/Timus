#include <bits/stdc++.h>


namespace task1297
{
    int solve(std::istream & in, std::ostream & out)
    {
        std::string s;
        in >> s;
        int n = (int)s.size();
        std::vector < std::vector <bool> > dp(n, std::vector <bool>(n, false));
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = (s[i] == s[i + 1]);
        for (int len = 2; len < n; ++len)
        {
            for (int i = 0; i + len < n; ++i)
            {
                int r = i + len;
                if (s[i] == s[r])
                {
                    dp[i][r] = dp[i + 1][r - 1];
                }
            }
        }
        int st = -1, max_len =  -1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (dp[i][j] && max_len < (j - i))
                {
                    st = i;
                    max_len =  j -  i;
                }
            }
        }
        for (int i = 0; i <= max_len; ++i)
        {
            out << s[st++];
        }
        out << std::endl;
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
        (void)task1297::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1297.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1297.out");
        int status = task1297::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
