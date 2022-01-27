    string colName (long long int n)
    {
        string s = "";
        while(n != 0) {
            // To make the number 0 indexed as we are taking remainder with 26.
            n--;
            int r = n % 26;
            s = string(1, r + 'A') + s;
            n = n / 26;
        }
        return s;
    }