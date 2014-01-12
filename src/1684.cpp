#include <bits/stdc++.h>


namespace task1684
{
    void kmp(const std::string & s, std::vector <int> & p)
    {
        int n = (int)s.size();
        for (int i = 1; i < n; ++i)
        {
            int j = p[i-1];
            while (j > 0 && s[i] != s[j]) j = p[j-1];
            p[i] = j + (s[i] == s[j]);
        }
    }


    int solve(std::istream & in, std::ostream & out)
    {
        std::string s, t;
        in >> s >> t;
        int n = (int)s.size();
        s += "#" + t;
        std::vector <int> p(s.size(), 0);
        kmp(s, p);
        bool yes = false;
        for (int i = n + 1; i < (int)p.size(); ++i)
        {
            if (p[i] == 0)
            {
                yes = true;
            }
        }
        if (yes)
        {
            out << "Yes\n";
        }
        else
        {
            out << "No\n";
            std::vector < int > pos;
            for (int i = (int)p.size() - 1; i > n;)
            {
                pos.push_back(p[i]);
                i -= p[i];
            }
            for (int i = (int)pos.size() - 1; i >= 0; --i)
            {
                out << s.substr(0, pos[i]) << " ";
            }
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
        (void)task1684::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1684.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1684.out");
        int status = task1684::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
