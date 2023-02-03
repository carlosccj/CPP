void eliminar(Lista& v, int valor)
{
    int pos = buscar(v, valor);
    if (0 <= pos && pos < v.nelms)
    {
        v.elm[pos] = v.elm[v.nelms-1];
        --v.nelms;
    }
}
