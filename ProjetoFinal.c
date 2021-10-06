#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>


typedef struct Aluno
{

    char nomeAlu[30] ;
    char cursoAlu[30] ;
    char matriculaAlu[15];
    float notaAlu[3];
    float mediaAlu ;

} Aluno;

//Aluno a[20] ;
int i = 0 ;
Aluno a[10];


void PermitirCaracterEspecial()
{

    setlocale(LC_ALL, "Portuguese"); //Acrescentar caracteres da língua portuguesa, ç,acentos,etc ...
};

void Login(char login[15], char senha[15])
{


    printf("\n");
    printf(" ___________________________\n");
    printf("|SISTEMA DE NOTAS ACADÊMICAS|\n");
    printf("|___________________________|");
    printf("\n|login: ");
    scanf("%s",login);
    printf("|___________________________|");
    printf("\n|Senha: ");
    scanf("%s",senha);
    printf("|___________________________|");
    printf("\n");
    system("cls");
}

void ExibirMenu()
{

    PermitirCaracterEspecial();
    system("color f2");
    printf("\n ________________________________________________\n");
    printf("|                   BEM VINDO !                  |\n");
    printf("|------------------------------------------------|\n");
    printf("|      SNA   -   Sistema de Notas Acadêmicas     |\n");
    printf("|------------------------------------------------|\n");
    printf("| 1 - Adicionar Aluno(a)                         |\n");
    printf("|------------------------------------------------|\n");
    printf("| 2 - Alterar Informações do Aluno(a)            |\n");
    printf("|------------------------------------------------|\n");
    printf("| 3 - Lançar Notas                               |\n");
    printf("|------------------------------------------------|\n");
    printf("| 4 - Editar Notas                               |\n");
    printf("|------------------------------------------------|\n");
    printf("| 5 - Buscar Aluno (a)                           |\n");
    printf("|------------------------------------------------|\n");
    printf("| 6 - listar alunos                              |\n");
    printf("|------------------------------------------------|\n");
    printf("| 7 - Sair                                       |\n");
    printf("|________________________________________________|\n");
}

void ExibirMenu5()
{

    printf("\n ________________________________________________________\n");
    printf("|                           |                            |\n");
    printf("|                           |                            |\n");
    printf("| 1- Buscar pelo nome       | 2 - Buscar pela Matrícula  |\n");
    printf("|                           |                            |\n");
    printf("|___________________________|____________________________|\n");
}

void SubMenu()
{

    printf("\n\n\n");
    printf("               ________________________________________________________\n");
    printf("              |                           |                            |\n");
    printf("              |                           |                            |\n");
    printf("              |       7- Para Sair        |  Pressione Qualquer Número |\n");
    printf("              |                           |    Para Voltar ao Menu...  |\n");
    printf("              |___________________________|____________________________|\n");

}

void AdicionarAluno ()
{


    printf("Nome: ");
    getchar();
    scanf("%[^\n]s",a[i].nomeAlu);
    printf("\nCurso: ");
    getchar();
    scanf("%[^\n]s",a[i].cursoAlu);
    printf("\nMatrícula: ");
    getchar();
    scanf("%[^\n]s",a[i].matriculaAlu);

    i++;

}

void AdicionarNotas(int w){
    int x = 0;


    for (x = 0 ; x < 3 ; x ++){
 printf("Digite a %d Nota do aluno: ",x+1);
   scanf("%f",&a[w].notaAlu[x]);
    }

    printf("\nNotadas Adicionadas com sucesso");
}


void ListarTodosALunos()
{

//fazer um for decrementando o i ...
    int j ;
    int notas;
    for(j=0 ; j < i  ; j++ )
    {
        //imprimir Dados do aluno
        printf("ID: %i\n",j+1);
        printf("Nome: %s", a[j].nomeAlu);
        printf("\nCurso: %s", a[j].cursoAlu);
        printf("\nMatrícula: %s", a[j].matriculaAlu);
        for(notas = 0 ; notas < 3 ; notas ++){
         printf("\nNotas: %0.2f ", a[j].notaAlu[notas]);
    }
        printf("\n\nMedia: %0.2f ", a[j].mediaAlu);
        printf("\n");
        printf("________________________");
        printf("\n");
    }

}

void BuscarPorMatricula()
{

    char buscarMatricula[30] ;
    int matriculasEncontradas = 0;

    printf("\nDigite a matrícula que deseja buscar: ");
    scanf("%s",buscarMatricula);

    printf("\n\nAlunos Encontrados na busca : \n");
    int j = 0;

    for(j=0 ; j < i  ; j++ )
    {
        if ( strcmp(buscarMatricula,a[j].matriculaAlu) == 0)
        {



            //imprimir Dados do aluno
            printf("\n");
            printf("Nome: %s", a[j].nomeAlu);
            printf("\nCurso: %s", a[j].cursoAlu);
            printf("\nMatrícula: %s", a[j].matriculaAlu);
            printf("\n");
            printf("________________________");
            printf("\n");

            matriculasEncontradas ++;

        }
    }
    if (matriculasEncontradas == 0)
    {

        printf("\nNenhum aluno encontrado!! ");

    }

}


void BuscarPorNome ()
{
    char buscarNome[30] ;
    int nomesEncontrados = 0;

    printf("\nDigite o nome que deseja buscar: ");
    getchar();
    scanf("%[^\n]s",buscarNome);
    nomesEncontrados = 0 ;

    printf("\n\nAlunos Encontrados na busca : \n");
    int j = 0;

    for(j=0 ; j < i  ; j++ )
    {
        if ( stricmp(buscarNome,a[j].nomeAlu) == 0)
        {



            //imprimir Dados do aluno
            printf("\n");
            printf("Nome: %s", a[j].nomeAlu);
            printf("\nCurso: %s", a[j].cursoAlu);
            printf("\nMatrícula: %s", a[j].matriculaAlu);
            printf("\n");
            printf("________________________");
            printf("\n");

            nomesEncontrados ++;

        }
    }
    if (nomesEncontrados == 0)
    {

        printf("\nNenhum aluno encontrado!! ");
    }


}

float Situacao(float n)
{
    if (n >= 6.0)
    {
        //retorna 0 caso o aluno esteja aprovado
        return 0 ;
    }
    else
        //retorna 1 caso contrário
        return 1 ;
}

void ImprimirSituacao(float media)
{

    //Imprimindo Situação
    if (Situacao(media) == 0)
    {
        printf("\nAPROVADO!");

    }
    else
    {
        printf("\nREPROVADO!");
    }

}



void ImprimirNotas(float n[3])
{
    int i;
    //imprimindo as notas
    for(i = 1 ; i <= 3 ; i ++)
    {
        printf("Nota da %dº Prova: %.2f\n",i,n[i]);

    }
    printf("\n");
}

float AcharMedia(float n[3])
{
    float total = 0;
    float media = 0;

    //calculando Soma de todas as notas
    total = n[1] + n[2] + n[3]  ;
    //achando a média da soma das notas
    media = total / 3 ;

    return media ;
}

void ImprimirMedia(float notas[3])
{

    float media = 0 ;

    media =  AcharMedia(notas);

    printf("Média: %.2f\n",media);

}

typedef struct Usuarios
{
    char login[15];
    char senha[15];
} Usuarios;


int main ()
{
    PermitirCaracterEspecial();

    //float n[3], media = 0 ;
    char login[15], senha[15];
   // char letra ;
   // char buscarMatricula[15];
    int opc ;
    int loginAutenticado = -1 ;
    int busca = 0;
    int codALuno ;

    //Criando um Login de usúrio

    Usuarios u1 ;
    strcpy(u1.login, "adm");
    strcpy(u1.senha, "1234");

    // Aluno a;

    while (loginAutenticado != 1 )   //Se repetir até login existir
    {

        Login(login,senha); //fazendo login
        printf("\nVerifificando usuário, Por Favor Aguarde ...\n");
        // Sleep(2000);
        system("cls");
        if ( strcmp(u1.login,login) == 0 && strcmp(u1.senha,senha)  == 0 )   //caso login exista, executa alguma coisa
        {

            loginAutenticado = 1 ;

            // printf("Logado com Sucesso ...");
            // Sleep(2000);
            system("cls");


            do
            {
                ExibirMenu();
                scanf("%d",& opc);
                system("cls");
                switch (opc)
                {

                case 1 :

                    AdicionarAluno();

                    printf("\nAluno Adicionado com Sucesso...");

                    Sleep(1000);

                    system("cls");

                    break ;

                case 2 :



                    break ;

                case 3 :

                    ListarTodosALunos();

                printf("\nEscolha o aluno que queria ADICIONAR Notas: ");
                scanf("%d",&codALuno);
                if (codALuno <= i && codALuno >= 0){

                    AdicionarNotas(codALuno-1);

                }else
                    {
                        printf("\nAluno Inexistente!!\n");

                    }


                    SubMenu();
                    scanf("%d",& opc);
                    system("cls");

                    break ;

                case 4 :

                    break ;

                case 5 :

                    do
                    {
                        system("cls");
                        ExibirMenu5();

                        printf("\nPor onde deseja buscar ?: ");
                        scanf("%d",&busca);

                        system("cls");

                        if (busca == 1)
                        {

                            BuscarPorNome();

                        }
                        else if
                        (busca == 2)
                        {

                            BuscarPorMatricula();

                        }
                        else
                        {
                            printf("\nOpção Inválida ! \n");
                            Sleep(1000);

                        }

                    }
                    while(busca != 1 && busca != 2);

                    SubMenu();

                    scanf("%d",& opc);
                    system("cls");

                    break ;

                case 6 :

                    ListarTodosALunos();
                    SubMenu();

                    scanf("%d",& opc);
                    system("cls");

                    break ;

                case 7 :


                    printf("\nSaindo ...");
                    Sleep(2000);
                    printf("\n\n");
                    //  system("pause");

                    break ;

                default :

                    printf("\nOpção Inválida !!!\nPor Favor Digite A opção desejada de 1 a 7. \n");

                    break ;
                }


            }
            while(opc != 7);

            // LancarNotas(a.nomeAlu[0],a.notaAlu[1],a.notaAlu[2]);

            /*
                    //imprimir Dados do aluno
                 printf("Nome: %s", a.nomeAlu);
                 printf("\nCurso: %s", a.cursoAlu);
                 printf("\nMatrícula: %s", a.matriculaAlu);
            */
            /*
               LancarNotas(n);
               ImprimirNotas(n);
               media = AcharMedia(n);
               ImprimirMedia(n);
               ImprimirSituacao(media);
            */
        }
        else
        {

            printf("\nLogin inexistente!!!\n");

            loginAutenticado = 0;

            printf("\nPor Favor Tente Novamente !...\n");
            Sleep(2000);
            system("cls");
        }
    }

    return 0;
}
