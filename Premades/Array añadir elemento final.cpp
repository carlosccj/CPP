void anyadir(Lista& v, int valor)
{
if (v.nelms < int(v.elm.size())) {
v.elm[v.nelms] = valor;
++v.nelms;
}
}
