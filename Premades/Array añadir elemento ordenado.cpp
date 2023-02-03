int buscar_posicion(const Lista& v, int valor)
{
    int i = 0;
    while ((i < v.nelms)&&(valor >= v.elm[i]))
    {
        ++i;
    }
    return i;
}
void anyadir_ord(Lista& v, int valor)
{
    if (v.nelms < int(v.elm.size()))
    {
        int pos = buscar_posicion(v, valor);
        for (int i = v.nelms-1; i >= pos; --i)
        {
            v.elm[i+1] = v.elm[i];
        }
        v.elm[pos] = valor;
        ++v.nelms;
    }
}
