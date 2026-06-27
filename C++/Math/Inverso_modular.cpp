//Inverso modular para contas do tipo b / a % m
//Eh necessario que gcd(a, m) = 1
//Sendo phi(m) a funcao totiente de euler
//Se m for primo, entao phi(m) = m - 1
int inv(int a, int phim){
    int e = phim - 1;
    return fexp(a, e);
}