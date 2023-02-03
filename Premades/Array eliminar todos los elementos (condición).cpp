void eliminar_todos(Lista& v, int valor)
{
    int j = 0;
    for (int i = 0; i < v.nelms; ++i)
    {
        if ( v.elm[i] != valor )
        {
            v.elm[j] = v.elm[i];
            ++j;
        }
    }
    v.nelms = j;
}
