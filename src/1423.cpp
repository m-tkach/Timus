#include <bits/stdc++.h>


namespace task1423
{
    void kmp(const std::string & s, std::vector <int> & p)
    {
        int n = (int)s.size();
        for (int i = 1; i < n; ++i)
        {
            int j = p[i - 1];
            while (j > 0 && s[i] != s[j])
            {
                j = p[j - 1];
            }
            if (s[i] == s[j])
            {
                ++j;
            }
            p[i] = j;
        }
    }


    int solve(std::istream & in, std::ostream & out)
    {
        int n;
        std::string s, t;
        in >> n >> s >> t;
        s += (char)1;
        s += t + t;
        std::vector <int> p(s.size(), 0);
        kmp(s, p);
        for (int i = n + 1; i < (int)p.size(); ++i)
        {
            if (p[i] == n)
            {
                out << i - 2 * n  << std::endl;
                return 0;
            }
        }
        out << -1 << std::endl;
        return -1;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    srand((unsigned)time(0));

#ifdef ONLINE_JUDGE
    do
    {
        (void)task1423::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1423.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1423.out");
        int status = task1423::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
