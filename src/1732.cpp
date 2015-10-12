#include <bits/stdc++.h>


namespace task1732
{
    class PrefixF
    {
    public:
        PrefixF();
        bool add(char c);
        void updatePrefix(const std::string & aPrefix);
        const std::vector <bool> & getU() const;
        void newString();

    private:
        std::vector <bool> u;
        std::vector <int> pp, sp;
        std::string prefix;
        bool last;
    };


    PrefixF::PrefixF()
        : last(false)
    {
    }


    bool PrefixF::add(char c)
    {
        if (last)
        {
            u.push_back(0);
            return last = false;
        }
        int j = sp.empty() ? pp[0] : sp.back();
        while (j && prefix[j] != c) j = pp[j-1];
        sp.push_back(j + (prefix[j] == c));
        u.push_back(0);
        if (sp.back() == prefix.size())
        {
            for (int i = 0, k = (int)u.size() - 1; i < (int)prefix.size(); ++i, --k)
            {
                u[k] = 1;
            }
            sp.clear();
            return last = true;
        }
        return last = false;
    }


    void PrefixF::updatePrefix(const std::string & aPrefix)
    {
        prefix = aPrefix;
        pp.resize(aPrefix.size());
        pp.assign(pp.size(), 0);
        for (int i = 1; i < prefix.size(); ++i)
        {
            int j = pp[i-1];
            while (j && prefix[i] != prefix[j]) j = pp[j-1];
            pp[i] = j + (prefix[i] == prefix[j]);
        }
    }


    const std::vector <bool> & PrefixF::getU() const
    {
        return u;
    }


    void PrefixF::newString()
    {
        sp.clear();
        last = false;
    }


    int solve(std::istream & in, std::ostream & out)
    {
        bool fail = true;
        std::string s;
        std::vector <std::string> x, y;
        std::vector < std::pair <int, int> > d;

        std::getline(in, s);
        std::stringstream ssx(s);
        while (ssx >> s) x.push_back(s);

        std::getline(in, s);
        std::stringstream ssy(s);
        while (ssy >> s) y.push_back(s);

        PrefixF foo;
        int j = 0;
        foo.updatePrefix(y[j++]);
        for (int i = 0; i < (int)x.size(); ++i)
        {
            for (int k = 0; k < (int)x[i].size(); ++k)
            {
                bool res = foo.add(x[i][k]);
                if (res)
                {
                    if (j < (int)y.size())
                    {
                        foo.updatePrefix(y[j++]);
                    }
                    else
                    {
                        fail = false;
                        foo.updatePrefix("$#$");
                    }
                }
            }
            foo.newString();
        }

        if (fail)
        {
            out << "I HAVE FAILED!!!\n";
            return 1;
        }

        const std::vector <bool> & u = foo.getU();
        j = 0;
        for (int i = 0; i < (int)x.size(); ++i)
        {
            if (i) out << " ";
            for (int k = 0; k < (int)x[i].size(); ++k)
            {
                if (u[j++])
                {
                    out << x[i][k];
                }
                else
                {
                    out << "_";
                }
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
        (void)task1732::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1732.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file isn't found!\n";
            break;
        }
        std::ofstream fout("../output/1732.out");
        int status = task1732::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
