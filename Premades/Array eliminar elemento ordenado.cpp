void eliminar_ord(Lista& v, int valor)
{
    int pos = buscar(v, valor);
    if (0 <= pos && pos < v.nelms)
    {
        for (int i = pos+1; i < v.nelms; ++i)
        {
            v.elm[i-1] = v.elm[i];
        }
        --v.nelms;
    }
}
