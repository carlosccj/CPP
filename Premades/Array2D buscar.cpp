void buscar2d(const Matriz& m, int x, int& ff, int& cc)
{
    ff = -1;
    cc = -1;
    for (int f = 0; (f < int(m.size())) && (ff < 0); ++f)
    {
        for (int c = 0; (c < int(m[f].size())) && (cc < 0); ++c)
        {
            if (x == m[f][c])
            {
                ff = f;
                cc = c;
            }
        }
    }
}
