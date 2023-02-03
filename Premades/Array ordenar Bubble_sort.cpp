void ordenar_burbuja(Lista& v)
{
    for (int k = 0; k < v.nelms-1; ++k)
    {
        for (int i = 0; i < v.nelms-1; ++i)
        {
            if (v.elm[i] > v.elm[i+1])
            {
// intercambiar(v.elm[i], v.elm[i+1]);
                int aux = v.elm[i];
                v.elm[i] = v.elm[i+1];
                v.elm[i+1] = aux;
            }
        }
    }
}
