#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/strings 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	 
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");	//cria o arquivo e o "w" � significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);	
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
		
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo / arquivo n�o encontrado\n\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system ("pause");
	}
}


int main() //int + op��o usado para definir vari�veis
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("---cart�rio de alunos da EBAC---\n\n");
	printf("Login de  administrador! \n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
		
	if(comparacao == 0)
	
	{
		system("cls");
		for (laco=1;laco=1;)
		{
	
			system("cls");

			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("---cart�rio de alunos da EBAC---\n\n"); //Inicio do menu
			printf("escolha a op��o desejada no menu abaixo: \n\n");
			printf("\t1 - Registrar nomes dos alunos\n");
			printf("\t2 - Consultar nomes dos alunos\n");
			printf("\t3 - Deletar nomes dos alunos\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("opcao: "); //fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
			system("cls"); //c�digo para limpar a tela
		
			switch(opcao) //inicio das escolhas 
			{
				case 1: 
				registro(); //chama as fun��es
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("obrigado por utilizar o sistema\n");
				return 0;
				break;
		
			
				default:
				printf("esta op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
				//fim das escolhas
	
			}		
		}
	}
	
	else
		printf("Senha incorreta!");
		
}

	
