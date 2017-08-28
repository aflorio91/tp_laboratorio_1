/** \brief Suma dos valores enteros
 *
 * \param Recibe un numero entero
 * \param Recibe un numero entero
 * \return Devuelve un entero
 *
 */
int suma(int A, int B)
{
    //printf("3- Calcular la suma (A+B)\n")
    return A+B;
}

/** \brief Resta dos valores enteros
 *
 * \param Recibe un numero entero
 * \param Recibe un numero entero
 * \return Devuelve un entero
 *
 */
int resta(int A, int B)
{
    //printf("4- Calcular la resta (A-B)\n");
    return A-B;
}
/** \brief Divide dos valores enteros
 *
 * \param Recibe un numero entero
 * \param Recibe un numero entero
 * \return Devuelve un entero
 *
 */
int division(int A, int B)
{
    //printf("5- Calcular la division (A/B)\n");
    int result;
    if (A == 0 || B ==0 || A < B)
    {
        result = 0;
    }
    {
        result = A/B;
    }
    return result;
}
/** \brief Multiplica dos valores enteros
 *
 * \param Recibe un numero entero
 * \param Recibe un numero entero
 * \return Devuelve un entero
 *
 */
int multiplicar(int A, int B)
{
    //printf("6- Calcular la multiplicacion (A*B)\n");
    return A*B;
}
/** \brief Factoriza un valor entero
 *
 * \param Recibe un numero entero
 * \param
 * \return Devuelve un entero
 *
 */
int factorizar(int A)
{
    //printf("7- Calcular el factorial (A!)\n");
    int result,temp,r;

    if(A==0)
    {
        result = 1;
    }
    else
    {
        temp = A-1;
        r = A;
        while (temp>=1)
        {
            r=r*temp;
            temp--;
        }
        result = r;
    }
    return result;
}
