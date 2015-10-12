#include <bits/stdc++.h>


namespace task1356
{
    std::vector<int> primes(1, 2);


    void gen_primes(const int kLimit)
    {
        for (int x = 3; x <= kLimit; x += 2)
        {
            bool is_p = true;
            for (int i = 0; primes[i] * 1ll * primes[i] <= 1ll * x && is_p; ++i)
            {
                if (x % primes[i] == 0)
                {
                    is_p = false;
                }
            }
            if (is_p)
            {
                primes.push_back(x);
            }
        }
    }


    bool is_prime(int x)
    {
        for (int i = 0; primes[i] * 1ll * primes[i] <= 1ll * x; ++i)
        {
            if (x % primes[i] == 0)
            {
                return false;
            }
        }
        return true;
    }


    int solve(std::istream & in, std::ostream & out)
    {
        gen_primes((int)1e5);
        int t;
        in >> t;
        while (t --> 0)
        {
            int n;
            in >> n;
            if (is_prime(n))
            {
                out << n << "\n";
            }
            else if (is_prime(n - 2))
            {
                out << 2 << " " << n - 2 << "\n";
            }
            else if (n % 2 == 0)
            {
                bool finish = false;
                for (int i = 1; !finish; ++i)
                {
                    int a = primes[i];
                    if (is_prime(n - a))
                    {
                        out << a << " " << n - a << "\n";
                        finish = true;
                    }
                }
            }
            else
            {
                bool finish = false;
                for (int i = 0; !finish; ++i)
                {
                    for (int j = 0; j <= i && !finish; ++j)
                    {
                        int a = primes[i];
                        int b = primes[j];
                        int c = n - a - b;
                        if (is_prime(c))
                        {
                            out << a << " " << b << " " << c << "\n";
                            finish = true;
                        }
                    }
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
        (void)task1356::solve(std::cin, std::cout);
    }
    while (0);
#else
    do
    {
        std::ifstream fin("../input/1356.in");
        if (!(fin.is_open()))
        {
            std::cerr << "The input file not found!\n";
            break;
        }
        std::ofstream fout("../output/1356.out");
        int status = task1356::solve(fin, fout);
        std::cout << status << std::endl;
        fout.close();
        fin.close();
    }
    while (0);
#endif // ONLINE_JUDGE

    return 0;
}
