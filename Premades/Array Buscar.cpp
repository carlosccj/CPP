int buscar(const Lista& v, int x)
{
    int i = 0;
    while ((i < v.nelms) && (x != v.elm[i]))
    {
        ++i;
    }
    if (i == v.nelms)
    {
        i = -1;
    }
    return i;
}
