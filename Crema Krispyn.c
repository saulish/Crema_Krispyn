#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int menu();//DECLARACION DE PROTOTIPOS
int pedido(struct datos *str;);
int modificar(struct datos *str;);
int mod_pedid(struct datos *str;);
int mod_dir(struct datos *str;);
int disponibilidad();
int ver(struct datos *str;);
int eliminar(struct datos *str;);
int salir();
struct datos {//ESTRUCTURA
    float precios[4];
    char nombre [20];
    char direccion [20];
    unsigned int pedidos[4];
    float total;
    unsigned int donas_total[4];
    };
int main()
{
    int i,opc,conf,pedid,ped=0;
    unsigned int donas_disp[4];
    donas_disp[0]=3;//AZUCAR
    donas_disp[1]=4;//CHOCOLATE
    donas_disp[2]=5;//MANZANA
    donas_disp[3]=6;//CHISPAS
    struct datos ptr;
    struct datos *str;
    str=&ptr;
    str->precios[0]=10;//AZUCAR
    str->precios[1]=15;//CHOCOLATE
    str->precios[2]=20;//MANZANA
    str->precios[3]=10;//CHISPAS
    for(i=0;i<4;i++)//ESTRUCTURA DE CONTROL REPETITIVA FOR
    {
        str->donas_total[i]=donas_disp[i];
    }
    while (conf!=1){//ESTRUCTURA DE CONTROL REPETITIVA WHILE
    system("cls");
    printf("Bienvenido a donas Krema Krispy\n");
    printf("Que desea hacer?\n");
    opc=menu(opc);
    switch (opc)//ESTRUCTURA DE CONTROL SELECTIVA MULTIPLE SWITCH
    {
    case 1://PEDIDO
        system("cls");
        if (ped==1)//ESTRUCTURA DE CONTROL SELECTIVA SIMPLE
        {
            printf("ya hay un pedido, deseas eliminarlo?\n");
            printf("[1]SI\n");
            printf("[2]NO \n");
            scanf("%i",&pedid);
            if (pedid==1)//ESTRUCTURA DE CONTROL SELECTIVA DOBLE
            {
              eliminar(&donas_disp,str);
              ped=0;
            }
        }
        else
            ped=pedido(&donas_disp, str,ped);
    break;
    case 2://MODIFICAR
        if (ped==0){//ESTRUCTURA DE CONTROL SELECTIVA DOBLE
            printf("No has realizado ningun pedido \n");
            system("Pause");
        break;
        }
        else{
            modificar(&donas_disp, str);
        }
    break;
    case 3://VER
        if (ped==0){//ESTRUCTURA DE CONTROL SELECTIVA DOBLE
            printf("No has realizado ningun pedido \n");
            system("Pause");
            break;
        }
        else{
            system("cls");
            disponibilidad(&donas_disp);
            ver(str);
        }
    break;
    case 4://SALIR
        conf=salir(conf,opc);
    break;
    }
    printf("Saul Isaac Sanchez Hernandez    218879131\n");
    printf("Carlos Fernando Rivas Jimenez   221977853\n");
    printf("Santiago Santiago Sanchez       217535331\n");
    }
    return 0;
}
int menu(int opc)
{
    printf("Menu \n");
    printf("1)Hacer un pedido\n");
    printf("2)Modificar pedidos\n");
    printf("3)Ver pedido\n");
    printf("4)Salir\n");
    do{//ESTRUCTURA DE CONTROL REPETITIVA DO WHILE
        printf("Ingresa una de las opciones: \n");
        scanf("%i",&opc);
        }while (opc >4);
    system("cls");
    return opc;
}
int pedido(int *donas_disp, struct datos* str,int ped )
{
    unsigned int i,conf;
    disponibilidad(donas_disp);
    printf("\n\n");
    str->total=0;
    printf("Vamos a hacer un pedido \n");
    for(i=0; i<4;i++)//ESTRUCTURA DE CONTROL REPETITIVA FOR
    {
        printf("Cuantas de las donas [%i]\n",(i+1));
        scanf("%i",&str->pedidos[i]);
        while (str->pedidos[i]>donas_disp[i])//ESTRUCTURA DE CONTROL REPETITIVA WHILE
            {
                printf("Cuantas de las donas [%i]\n",(i+1));
                scanf("%i",&str->pedidos[i]);
            }
    if (donas_disp[i]>0)//ESTRUCTURA DE CONTROL SELECTIVA DOBLE
        {
            donas_disp[i]-=str->pedidos[i];
        }
    else
        {
            printf("No hay mas de estas donas\n");
        }
    }
    printf("Deseas ingresar una direccion de entrega? \n");
    printf("[1] Si\n");
    printf("[2] No\n");
    scanf("%i",&conf);
    if (conf==1)//ESTRUCTURA DE CONTROL SELECTIVA SIMPLE
    {
        system("cls");
        mod_dir(str);
    }
    return 1;

}
int modificar (int *donas_disp, struct datos* str)
{
    system("cls");
    unsigned int opc,cambio;
    printf("Que deseas modificar?\n");
    printf("[1]La donas\n");
    printf("[2]La direccion\n");
    scanf("%i",&opc);
    while(opc>2)//ESTRUCTURA DE CONTROL REPETITIVA WHILE
        {
            scanf("%i",&opc);
        }
    if (opc==1)//ESTRUCTURA DE CONTROL SELECTIVA DOBLE
        {
            system("cls");
            disponibilidad(donas_disp);
            cambio=mod_pedid(&donas_disp, str);
            donas_disp[cambio]=str->donas_total[cambio]-str->pedidos[cambio];
        }
    else
        {
            mod_dir(str);
        }
    system("pause");
    return 0;
}
int mod_pedid(int *donas_disp, struct datos* str)
{
    unsigned int opc;
    ver(str);
    printf("Cual deseas modificar? \n");
    scanf("%i",&opc);
    while (opc>4)//ESTRUCTURA DE CONTROL REPETITIVA WHILE
    {
        printf("No disponible\n");
        scanf("%i",&opc);
    }
    opc=opc-1;
    printf("Por cuanto lo quieres modificar: \n");
    scanf("%i",&str->pedidos[opc]);
    while (str->pedidos[opc] > str->donas_total[opc])//ESTRUCTURA DE CONTROL REPETITIVA WHILE
    {
        printf("No hay tantas donas :(\n");
        scanf("%i",&str->pedidos[opc]);
    }
    return opc;
}
int mod_dir(struct datos* str)
{
    fflush(stdin);
    printf("Ingresa tu nombre\n");
    gets(str->nombre);
    printf("\n");
    printf("Ahora tu direccion\n");
    gets(str->direccion);
    system("pause");
    return 0;
}
int disponibilidad(int *donas_disp)
{
    printf("Las donas disponibles son: \n\n");
    printf("[1] Dona de azucar             Hay  [%i] precio 10$\n",donas_disp[0]);
    printf("[2] Dona de chocolate          Hay  [%i] precio 15$\n",donas_disp[1]);
    printf("[3] Dona de manzana            Hay  [%i] precio 20$\n",donas_disp[2]);
    printf("[4] Dona de chispas de colores Hay  [%i] precio 10$\n",donas_disp[3]);
    system("pause");
    return 0;
}
int ver(struct datos* str)
{
    str->total=0;
    int i;
    printf("Tu pedido es: \n");
    for (i=0;i<4; i++){//ESTRUCTURA DE CONTROL REPETITIVA FOR
        printf("Donas [%i] Pediste %i\n",(i+1),str->pedidos[i]);
        str->total+=(str->pedidos[i]*str->precios[i]);
    }
    printf("El total es: %.2f \n",str->total);
    printf("Esta a nombre de ");
    puts(str->nombre);
    printf("La direccion es ");
    puts(str->direccion);
    system("pause");
    return 0;
}
int eliminar(int *donas_disp,struct datos* str)
{
    int i;
    for (i=0;i<4;i++)//ESTRUCTURA DE CONTROL REPETITIVA FOR
    {
        str->pedidos[i]=0;
        donas_disp[i]=3+i;
    }
    return 0;
}
int salir(int conf ,int opc)
{
    system("cls");
    printf("1) Para salir \n");
    printf("0) Para cancelar \n");
    scanf("%i",&conf);
    return conf;
}
