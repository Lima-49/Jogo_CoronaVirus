/* Jogo para conscientização | Higiene em tempos de pandemia| */

/* ============= BIBLIOTECAS UTILIZADAS ============= */
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>					//para acentos e carcteres especias (linguagem), lembrando que não é tradução
#include<conio.h>        			//para configurações gráficas
#include <windows.h> 				//biblioteca necessária para as configurações de saída cor, etc...

#define Q 30

/* ============= PROTÓTIPOS =============*/
int menu();     					//protótipo da função menu
void instru(); 						//protótipo da função para instruções do jogo
void configurarJogo(); 				//protótipo da função para definir o nome do jogador
void fases();						//protótipo para função de seleção das fases 
void creditos();					//protótipo para créditos aos desenvolvedores	
void introducao();					//protótipo da função de introdução
void questao1();					//protótipo da função da questão 1 Fase1
void questao2();					//protótipo da função da terceira Fase
void questao3();					//protótipo da função da terceira Fase
void fim();							//protótipo da função da terceira Fase
void questao2();					//protótipo da função questão 2 da fase 1
void questao3();					//protótipo da função questão 3 fase 1
//===============Funções Rafael
void questao10();
void questao11();
void questao12();
void questao13();
void bonus();
void fimdejogo();
//===============Funções Rafael


/* ============= VARIÁVEIS GLOBAIS =============*/
char nomeJogador[Q];   			    //para armazenar o nome do jogador
int vida = 3;						//total de vidas do jogador
char selo[2];


// função principal
int main(){
	
	setlocale(LC_ALL, "");
	int opcao;
	
	system('cls');
	printf("\t\t\t    #===================#\n");
	printf("\n\t\t\t   Bem Vindo ao Nosso Jogo \n");
	printf("\n\t\t\tEsperamos que você se Divirta.\n\n\n");
	printf("\t\t\t    #===================#\n\n\n");
	printf("\t\t   A história do Jogo se Basea no Dia a dia,\n");
	printf("\t\tde pessoas diante a pandemia do Corona Vírus.\n\n\n");
	printf("\n\t\t    Pressione qualquer tecla para Continuar. ");	
	getche();

	opcao=menu();
	
	if(opcao == 1)
	{
		introducao();
	}
	else if(opcao == 2)
	{
		configurarJogo();
	}
	else if(opcao == 3)
	{
		instru();
	}
	else if(opcao == 4)
	{
		creditos();
	}
	
	return 0;
}

//menu
int menu(){ 
	
	int op, i, a=0;
	system("CLS");	
	
	for(i=0; i<=2; i++)
	{
		system("CLS");	
		printf("\n\n\n\t\t\t    #========================#\n");
		printf("\t\t\t#==#\t\t\t      #==#\n");
		printf("\t\t\t#    \t\t\t         #");
		printf("\n\n\t\t\t         Escolha uma opção:\n\n\n");
		printf("\t\t\t        1 - Iniciar o jogo.\n");
		printf("\t\t\t        2 - Configurações.\n");
		printf("\t\t\t        3 - Instruções.\n\n\n");
		printf("\t\t\t        4 - Créditos.\n\n\n");
		printf("\t\t\t#    \t\t\t         #\n");
		printf("\t\t\t#==#\t\t\t      #==#\n");
		printf("\t\t\t    #========================#\n");
		printf("\n\n\t\t\t\t\t");scanf(" %d", &op);
		
		if(op == 1 || op == 2 || op == 3 || op == 4)
		{
			return op;
		}
		else if((op != 1 || op != 2 || op != 3 || op != 4) && a<2)
		{
			a++;
		}		
	}
	
	printf("\t\t        Opção Inválida digitada mais de 3x!!!\n");
}


void fases(){
	
	int fase, i, a;
	
	printf("\n  Então vamos lá !!!");
	_sleep(3000);
	
	for(i=0; i<=2; i++)
	{
		system("CLS");
		printf("\n\n\t\t\t#===============#");
		printf("\n\n\t\t\tSelecione uma Fase");
		printf("\n\n\t\t\t#===============#\n\n\n\n");
		printf("\n\t\t1 - Dentro de Casa.  Fácil \n\t\t2 - No Comércio.     Médio \n\t\t3 - Hospital.       Díficil \n\n\n");
		printf("\t\t\t    Fase: ");
		
		scanf(" %d", &fase);
		
		if(fase==1)
		{
			questao1();
		}
		else if(fase==2)
		{
			questao10();  
		}
		else if(fase==3)
		{
			terceiraFase();
		}
		
		if((fase != 1 || fase != 2 || fase != 3 ) && a<2)
		{
			a++;
		}		
	}
	printf("\t\t        Opção Inválida digitada mais de 3x!!!\n");
}


//função para crédito aos desenvolvedores
void creditos()
{	
	system("cls");
	printf("\n\t\t\tEste projeto foi desenvolvido por:\n\n\t  - Natanael Vitorino, Vitor Augusto e Rafael Azolini.\n\t\t  Alunos do primeiro semestre de Eng. de Computação. -\n\t\t\t     DATA: 22/05/2020\n\n\t\t    Pressione qualquer tecla para voltar...");
	getche();
	system("cls");
	menu();	
}

//instruções do jogo
void instru(){ 
	
	int i;
	char ok;
	
	system("CLS");
	printf("\n  Este jogo é para a conscientização de forma divertida e interativa, tenha responsabilidade e aprenda jogando\n  a como ser precavido em determinadas circunstâncias.\n\n");
	printf("  Configurações de cores:\n  Gótico - Vermelho e Preto\n  Ket - Rosa e Preto\n  Verde - Verde e Preto\n  Roxo - Roxo e Branco\n");
	puts("");
	printf("  Partiu jogar? <s/n>\n  ");
	scanf(" %c", &ok);
	
	if(ok == 's' || ok == 'S')
	{
		configurarJogo();
	}
	else if(ok == 'n' || ok == 'N')
	{
		system("cls");
		main();
	}
	
	if((ok != 'S' || ok !='s') && (ok != 'n' || ok != 'N'))  //verificação de opção correta digitada pelo usuário
	{
		for(i=0; i<=2; i++)
		{
			system("cls");
			printf("\n  Opção Inválida!!! Digite novamente...\n");
			printf("  Partiu jogar? <s/n>\n  ");
			scanf(" %c", & ok);
				
			if(ok == 's' || ok == 'S')
			{
				configurarJogo();
			}
			else if(ok == 'n' || ok == 'N')
			{
				system("cls");
				main();
			}
		}
		system("cls");
		printf("\n  Que insistencia, em?!\n  Você será direcionado ao menu inical...");
		_sleep(3000);
		main();
	}
}

//definir as configurações do jogo
void configurarJogo(){
		
	int temaJogo;   //para o tema do jogo
	int i, a; 		//variáveis para manipulações
		
	system("CLS");
	
	printf("\n\n\t\t\t  Selecione o Tema do Jogo: \n\n\n\t\t\t       1 - Vermelho.\n\t\t\t       2 - Ket.\n\t\t\t       3 - Verde.\n\t\t\t       4 - Roxo.\n\n\n\t\t\t   Tema escolhido: ");
	scanf(" %d", &temaJogo);
	
	printf("\n\t\t   Nome do Personagem: "); 
	scanf(" %s", nomeJogador);
	
	
	if(temaJogo < 1 || temaJogo > 4) //verificação do valor digitado pelo usuário
	{
		do{
			system("cls");
			printf("\n\t\t\t  Digite uma opção válida");
			printf("\n\n\t\t\t  Selecione o Tema do Jogo: \n\n\n\t\t\t       1 - Vermelho.\n\t\t\t       2 - Rosa.\n\t\t\t       3 - Verde.\n\t\t\t       4 - Roxo.\n\n\n\t\t\t   Tema escolhido: ");
			scanf(" %d", &temaJogo);
			
			if(temaJogo >= 1 && temaJogo <= 4)
			{
				i=3;
			}
			else 
			{
				i=0;
			}
	 	}while(i == 0);
	}
	
	puts("");
	
	//Condicionais para a seleção do tema do jogo
	if(temaJogo == 1)
	{
		system("color 40");
		printf("  Digite qualquer tecla para iniciar...");
		getch(); 
		system("CLS");
		introducao();
	}
	else if(temaJogo == 2)
	{
		system("color D0");
		printf("  Digite qualquer tecla para iniciar...");
		getch(); 
		system("CLS");
		introducao();
	}
	else if(temaJogo == 3)
	{
		system("color 20");
		printf("  Digite qualquer tecla para iniciar...");
		getch(); 
		system("CLS");
		
		introducao();
	}
	else if(temaJogo == 4)
	{
		system("color 5F");
		printf("  Digite qualquer tecla para iniciar...");
		getch(); 
		system("CLS");
		introducao();
	}
}

//Função para a introdução do jogo
void introducao(){
	
	int op, i;
	char resp;
	
	system("cls");
	printf("\n\t\tM - Voltar ao menu        F - Sair do jogo\n\n\n\n", vida);
	printf("\t\t\t\t#==========#\n\n");
	printf("\t\t\t\t  História.\n\n");
	printf("\t\t\t\t#==========#\n\n\n\n");
	printf("\tO ano é 2020, e um novo vírus é descoberto nos Confins da China,\n"); 
	printf("\tesse acaba assolando o mundo em que vivemos.\n\n\tA Organização Mundial da Saúde (OMS) passou a chamar oficialmente\n");
	printf("\ta doença causada pelo novo coronavírus de Covid-19.\n\n\n\tCOVID significa COrona VIrus Disease (Doença do Coronavírus),\n");printf("\tenquanto “19” se refere a 2019, quando os primeiros \n\tcasos em Wuhan, na China, foram divulgados. \n\n\n\n\t\t\tOs sintomas do Covid são:\n\n\n\t  - Febre que não sessam com remédios.\n\t  - Tosse seca.\n\t  - Dificuldades para respirar.\n\t  - Dor no corpo.\n\n\n");
	printf("\tPor causa dele, nossas vidas foram interrompidas,\n");printf("\te é Nosso o dever de conter esse vírus.\n\n\n\n\n");
	printf("\t\t%s Você está pronto(a) para esta Aventura ? \n\n", nomeJogador);
	printf("\t\t  Pressione S, Para Continuar ou N para sair.\n\n\t\t\t\t\t");
	scanf(" %c", &resp);
	
	if(resp=='M'||resp=='m')
	{
	main();
	}
	else if(resp=='F'||resp=='f')
	{
	return 0;
	}
	
	if(resp=='S'||resp=='s')
	{
	fases();	
	}
	else if(resp=='n'||resp=='N')
	{
	system("CLS");
	main();
	}
	
	if(resp!='S'||resp!='s'&&resp!='n'||resp!='N')  //verificação de opção correta digitada pelo usuário
	{
		for(i=0; i<=2; i++)
		{
			system("cls");
			printf("\n  Opção Inválida!!! Digite novamente...\n");
			printf("  Partiu jogar? <s/n>\n  ");
			scanf(" %c", & resp);
			
			if(resp=='s'||resp=='S')
			{
			fases();
			}
			else if(resp=='n'||resp=='N')
			{
			main();
			}
		}
	}
}



//Primeira fase do jogo
//=============================================== Parte Vitor

void questao1(){
	
	int i; 
	char opcao;
	
	system("cls");
	printf("\n\n\n\n\tNúmero de Vidas %d     M - Voltar ao Menu      F - Sair do Jogo\n\n",vida);  
	printf("\n\n\t\t   Olá, Obrigado por escolher minha fase \n");
   	puts("\n\n\n\t\tDepois de um dia cheio de afazeres DENTRO DE CASA,");
	printf("\t  e sem paciência nenhuma de ir para a cozinha fazer a janta,\n");
	puts("\t  então %s decide pedir um delivery do seu restaurante favorito.\n\n\n");
	printf("     Depois de um tempo, finalmente você escuta a buzina em frente a sua casa");
	printf("\t\t    De que maneira você atende a porta ? \n\n\n\n");
	printf("\t   (A) - Saio com máscara e passo álcool em gel nas mãos e na embalagem.");
	printf("\t   (B) - Saio com máscara e com fome, mas não higienizo a embalagem.\n");
	printf("\t   (C) - Mando meu irmão asmático, ir pegar a entrega.\n\n\n\n");
	printf("\t\t\tSua Resposta é : ");scanf(" %c", &opcao);
	
	if(opcao=='m'||opcao=='M')
	{
		main();
	}
	else if(opcao=='f'||opcao=='F')
	{
		system("cls");
		printf("\n\n\t\t\tVocê Fechou o Jogo\n\n\n\n");
		return 0;
	}
	
	if(opcao=='a'||opcao=='A')
	{
		questao2();
    }
	else if(opcao=='b'||opcao=='B'||opcao=='c'||opcao=='C')//CASO UMA DESSAS OPÇÕES FOREM ESCOLIDAS, SERÁ DESCONTADO UMA VIDA
	{
		system("CLS");
		vida--;
		printf("\n\n\t\tVOCÊ TEM APENAS %d VIDAS, TENHA CUIDADO\n", vida);
		puts("\n\n\t\tPressione qualquer tecla para continuar.");
		getch( );
		questao2();
	}
	
	if(opcao!='a'||opcao!='A'||opcao!='b'||opcao!='B'||opcao!='c'||opcao!='C'||opcao!='m'||opcao!='M'||opcao!='f'||opcao!='F')  
	{
		for(i=0; i<=2; i++)
		{
			system("cls");
			printf("\n\n\n\t\t   Opção Inválida!!! Digite novamente...\n\n\n");
			printf("\n\t   Pressione qualquer tecla para voltar para a Última Pergunta.\n");
			getch();
			questao1();
		}
 	 }
}

//FUNÇÃO PARA QUESTÃO 2
void questao2()
{
	char opcao;
	int i;
	
	system("CLS");
	printf("\n\tNúmero de Vidas %d     M - Voltar ao Menu      F - Sair do Jogo\n\n",vida); 
    puts("\n\n\t\tVocê precisa pagar suas contas no Banco");
    puts("\t\tDe que maneira você se comporta ?\n\n\n");

    printf("\t(A) - Uso máscara, mas sem cobrir o nariz, pago em dinheiro,\n");
	printf("\tpego o troco e comprimento com aperto de mão meus amigos na fila,\n"); 
	printf("\tmas chegando em casa uso álcool gel.\n\n");
    printf("\t(B) - Uso máscara aproveito que estou fora de casa, encontro meus amigos");
	printf("\tsem máscara, comprimento-os, e volto para casa e conto as novidades\n");
	printf("\tpara o meu pai diabético.\n\n");
	printf("\t(C) - Uso máscara, mantenho uma distância de 2 metros,\n"); 
	printf("\tdas pessoas da fila,e ao voltar pra casa deixo a roupa para lavar,");
	printf("\t\te entro tomar um banho\n\n\n");
	printf("\t\t\t\tO que você Faz ? ");
	scanf(" %c", &opcao);

	if(opcao=='m'||opcao=='M')
	{
	main();
	}
	else if(opcao=='f'||opcao=='F')
	{
	system("cls");
	printf("\n\n\t\t\tVocê Fechou o Jogo\n\n\n\n");
	return 0;
	}
	if(opcao=='c'||opcao=='C')
	{
	questao3();
    }
	else if(opcao=='a'||opcao=='A'||opcao=='b'||opcao=='B')//CASO UMA DESSAS OPÇÕES FOREM ESCOLIDAS, SERÁ DESCONTADO UMA VIDA
	{
	system("CLS");
	vida--;
	printf("\n\n\t\tVOCÊ TEM APENAS %d VIDAS, TENHA CUIDADO\n", vida);
	puts("\n\n\t\tPressione qualquer tecla para continuar.");
	getch( );
	questao3();
	}
	
	if(opcao!='a'||opcao!='A'||opcao!='b'||opcao!='B'||opcao!='c'||opcao!='C'||opcao!='m'||opcao!='M'||opcao!='f'||opcao!='F')  
	{
	for(i=0; i<=2; i++)
	{
	system("cls");
	printf("\n\n\n\t\t   Opção Inválida!!! Digite novamente...\n\n\n");
	printf("\n\t   Pressione qualquer tecla para voltar para a Última Pergunta.\n");
	getch();
	questao2();
	}
}
}

//FUNÇÃO PARA A QUESTÃO 3
void questao3()
{
	char opcao;
	int i;
	 
    system("CLS");
    printf("\n\tNúmero de Vidas %d     M - Voltar ao Menu      F - Sair do Jogo\n",vida); 
	puts("\n\n\n\t   Minha internet caiu, preciso de um técnico para fazer o reparo");
    puts("\t\t\tComo recebo o técnico ?\n\n");

	printf("\t(A) - Recebo o técnico de máscara, e ele usando máscara e luvas.\n");
	printf("\tDepois de finalizar o reparo, o compriento com um aperto de mão.\n\n");
	printf("\t(B) - Ele esta de máscara e luvas, e conversamos com uma certa distância\n");
	printf("\t(C) - Técnico chega sem máscara e sem luva, eu usando máscara e luvas,\n");
	printf("\tcomprimento-o, Quando o reparo termina, me despeço do técnico,\n");
	printf("\te descarto as luvas.\n\n\n");
	printf("\t\t\t\tO que você Faz ? ");scanf(" %c",&opcao);
		
	if(opcao=='m'||opcao=='M')
	{
	main();
	}
	else if(opcao=='f'||opcao=='F')
	{
	system("cls");
	printf("\n\n\t\t\tVocê Fechou o Jogo\n\n\n\n");
	return 0;
	}
	if(opcao=='b'||opcao=='B')
	{
	fim();
    }
	else if(opcao=='a'||opcao=='A'||opcao=='c'||opcao=='C')//CASO UMA DESSAS OPÇÕES FOREM ESCOLIDAS, SERÁ DESCONTADO UMA VIDA
	{
	system("CLS");
	vida--;
	printf("\n\n\t\tVOCÊ TEM APENAS %d VIDAS, TENHA CUIDADO\n", vida);
	puts("\n\n\t\tPressione qualquer tecla para continuar.");
	getch( );
	fim();
	}
	
	if(opcao!='a'||opcao!='A'||opcao!='b'||opcao!='B'||opcao!='c'||opcao!='C'||opcao!='m'||opcao!='M'||opcao!='f'||opcao!='F')  
	{
	for(i=0; i<=2; i++)
	{
	system("cls");
	printf("\n\n\n\t\t   Opção Inválida!!! Digite novamente...\n\n\n");
	printf("\n\t   Pressione qualquer tecla para voltar para a Última Pergunta.\n");
	getch();
	questao3();
	}
}
}

void fim()
{
	int j;
	
	system("CLS");
	printf("\n\n\n\t\t\t\tParabéns !!!\n");
	printf("\t\t\t   Obrigado por Jogar.\n\n\n");
	printf("\t\t\tSua Quantidade de Vidas %d\n\n\n",vida);
	printf("\t\t 1 - Voltar ao Menu Principal. \n");
	printf("\t\t 2 - Para jogar novamente esse nível.\n");scanf(" %d",&j);
	if(j==1)
	{
	main();	
	}
	else if(j==2)
	{
	questao1();	
	}
}


//=============================================== Parte Vitor



//====================================================== Parte Rafael
//Segunda Fase - Na Rua
void questao10()
{
	char escolha1;
	int i;
	
	system("CLS"); 
	printf("\n\t\t  M - Voltar ao Menu      F - Sair do Jogo\n\n");   
	printf("\n\n\t\t  Olá, Obrigado por escolher minha fase \n");
	printf("\n\n\t  %s Você sendo um dono de restaurante, precisa vender seus salgados,",nomeJogador);
	printf("\n\t  porém como prosseguir diante disso ?\n\n\n");
	printf("\n\t\t            Você tem algumas escolhas:\n\n\n");
	printf("\t\t  (A) - Abrir a loja mesmo sendo contra a lei.\n"); 
	printf("\t\t  (B) - Ficar fechado e perder vendas.\n");
	printf("\t\t  (C) - Protestar contra o Governo.\n"); 
	printf("\n\n\n");
	printf("\t\t\t     Sua Resposta é: ");scanf(" %c",&escolha1); 
	printf("\n");
	
	if(escolha1=='a'||escolha1=='A')
	{
		fimdejogo();
	}
	else if(escolha1=='b'||escolha1=='B')
	{
		questao11();
	}
	else if(escolha1=='c'||escolha1=='C')
	{
		bonus();
	}
	else if(escolha1=='f'||escolha1=='F')
	{
		_sleep(700);
		return 0;
	}
	else if(escolha1=='m'||escolha1=='M')
	{
		_sleep(700);
		main();	
	}
	
	if((escolha1!='a'||escolha1!='A') && (escolha1!='b'||escolha1!='B') && (escolha1!='c'&&escolha1!='C'))
	{
		for(i=0; i<=2; i++)
		{
		system("cls");
		printf("\n\n\n\t\t   Opção Inválida!!! Digite novamente...\n\n\n");
		printf("\n\t   Pressione qualquer tecla para voltar para a Última Pergunta.\n");
		getch();
		questao10();
		}	
	}
}

void questao11()
{
	char escolha2;
	int i;
	
	system("CLS");
	printf("\n\t\t  M - Voltar ao menu      F - Sair do jogo\n\n");        
	printf("\n\n\t\t      Certo você %s mantêm a loja fechada\n\n\n",nomeJogador);
	printf("\t   Porém sua Familía precisa de dinheiro pra sobreviver\n");
	printf("\t   o que você faz ?\n\n\n");
	printf("\t\t(A) - Solicita o Auxilio Emergencial. \n");
	printf("\t\t(B) - Decide Arrumar dinheiro de outra forma.\n\n\n\n");
	printf("\t\t\tSua Resposta é: ");scanf(" %c",&escolha2);
	printf("\n");
	
	if(escolha2=='a'||escolha2=='A')
	{
		questao13();
	}
	else if(escolha2=='b'||escolha2=='B')
	{
		questao12();
	}	
	else if(escolha2=='f'||escolha2=='F')
	{
		_sleep(700);
		return 0;
	}
	else if(escolha2=='m'||escolha2=='M')
	{
		_sleep(700);	
		main();	
	}
	
	if(escolha2!='a'||escolha2!='A'&&escolha2!='b'||escolha2!='B')  
	{
		for(i=0; i<=2; i++)
		{
		system("cls");
		printf("\n\n\n\t\t   Opção Inválida!!! Digite novamente...\n\n\n");
		printf("\n\t   Pressione qualquer tecla para voltar para a Última Pergunta.\n");
		getch();
		questao11();
		}
	}
}

void questao13()
{
	
	system("CLS");          
	printf("\n\n");
	printf("\t\t     Você solicitou o Auxilio Emergencial\n\n\n");
	printf("\t\t\tMas a fila tem muuuitas pessoas\n");
	printf("\t\tAssim você deixa seu filho na fila kkkkkkkkk,\n");
	printf("\t\te decide arrumar seu sustento de outra forma.\n\n");
	printf("\t\t\tEntão você continua sem dinheiro\n");
	printf("\t\t     Logo você retorna a situação anterior.\n\n\n");
	printf("\t\t\t Pressione Enter para voltar\n");
	getche();
	questao11();	
}

void questao12()
{
	char escolha3;
	int j;
	
	system("CLS");   
	printf("\n\t\t  M - Voltar ao menu      F - Sair do jogo\n\n");            
	printf("\n\n\n\t\tSua maneira de decidir como ganhar uma renda é\n");
	printf("\t\tfazendo máscaras ou vendendo álcool em gel.\n\n\n");
	printf("\t\t    O que você escolhe para vender ?\n\n\n");
	printf("\t\t       (A) - Para Máscaras.\n \t\t       (B) - Para Ácool em Gel.\n");
	printf("\t\t\t\t   ");scanf(" %c",&escolha3);
	
	if(escolha3=='f'||escolha3=='F')
	{
		_sleep(700);
		return 0;
	}
	else if(escolha3=='m'||escolha3=='M')
	{
		_sleep(700);	
		main();	
	}

	if(escolha3=='a'||escolha3=='A')
	{
		system("CLS");
		printf("\n\n\t\t\t  Você escolheu vender máscaras,\n");
		printf("\t\tlogo conseguiu um sustento e ajudou a comunidade.\n\n");
		printf("\t\tAhhh e Seu filho retorna com o Auxilio Emergencial.\n\n\n");
		printf("\t\t\t\tParabéns\n");
		printf("\t\t\t   Obrigado por Jogar.\n\n\n");
		printf("\t\t 1 - Voltar ao Menu Principal. \n");
		printf("\t\t 2 - Para jogar novamente esse nível.\n");scanf(" %d",&j);
		if(j==1)
		{
			main();
		}
		else if(j==2)
		{
			questao10();	
		}
	}
	else if(escolha3=='b'||escolha3=='B')
	{
	system("CLS"); 		
	printf("\n\n\t\tVocê escolheu vender álcool em gel e Ganhou tipo,\n");
	printf("\t\t\tMUITO DINHEIRO, MUITO MESMO.\n\n\n");
	printf("\t\tAhhh e Seu filho retorna com o Auxilio Emergencial.\n\n\n");
	printf("\t\t\t\tParabéns\n");
	printf("\t\t\t   Obrigado por Jogar.\n\n\n");
	printf("\t\t 1 - Voltar ao Menu Principal. \n");
	printf("\t\t 2 - Para jogar novamente esse nível.\n");scanf(" %d",&j);
	
	if(j==1)
	{
		main();
	}
	else if(j==2)
	{
		questao10();	
	}
	}
}



void fimdejogo()
{
	int i,j;
	
	system("CLS"); 
	printf("\n\n\t  Sério mesmo que você foi contra a lei ? SKAJDKJAKSDJ\n");
	printf("\t\tO Governo te prendeu e você pegou Corona.  \n\n\n");
	printf("\t\t  Pra você Aprender a ficar em casa.\n\n\n");
	printf("\t\t\t Tenta Mais uma Vez vai \n\n\n");
	printf("\t\t   1 - Para recomeçar o nível\n"); 
	printf("\t\t   2 - Para retornar o Menu Principal\n");scanf("%d",&j);
	
	if(j==1)
	{
		questao10();
	}
	else if(j==2)
	{
		main();
	}
	
	
}

void bonus()
{
	int i,j;
	
	system("CLS");  
	printf("\n\n\t\t %s protestou contra o Governo\n",nomeJogador);
	printf("\t\tlevou um Cacete, e foi preso.\n\n");
	printf("\n\t\t\tFim de Jogo :( \n\n\n");

	printf("\t\t 1 - Para recomeçar o nível.\n"); 
	printf("\t\t 2 - Para retornar o Menu Principal.\n");scanf("%d",&j);
	
	if(j==1)
	{
		questao10();
	}
	else if(j==2)
	{
		main();
	}
	
	if(j!='1'||j!='2')  
	{
		for(i=0; i<=2; i++)
		{
		system("cls");
		printf("\n\n\n\t\t   Opção Inválida!!! Digite novamente...\n\n\n");
		printf("\n\t   Pressione qualquer tecla para voltar para a Última Pergunta.\n");
		getch();
		questao12();
		}
	}
}


//=============================================== Parte Rafael

	
	


//Terceira Fase - Hospital
//=============================================== Parte Natanael
void terceiraFase(){
	
	char alternativaUm;
	
	system("cls");
	printf("\n\t         M - Voltar ao menu        F - Sair do jogo\n\n", vida);
	printf("\n\n\t\t   Olá, Obrigado por escolher minha fase\n");
	printf("\n\t     Você é um médico e está no combate direto ao COVID-19.\n");
	printf("\t     Em um de seus plantões, enquanto passava pelo corredor B,\n");
	printf("   do setor de infectados, o Seu José espirra e as goticulas caem no seu jaleco\n\n\n\t\t\tO que você faria Dr. %s?\n\n", nomeJogador);
	printf("\n  (A) Você passa a mão em um pedaço de pau e bate no Seu José.\n  (B) Sai correndo e se tranca no banheiro e fica lá semanas.\n  (C) Comprimenta de longe o seu José, ensina ele a como evitar esse\n  tipo de situação, higieniza as suas mãos e locais afetatos pelo espirro.\n\n  (D) Espero o corona me pegar e me despeço da minha familia.");
	printf("\n\n\t\t\tSelecione a alternativa: ");
	scanf(" %c", & alternativaUm);
	
	if(alternativaUm == 'M' || alternativaUm == 'm')
	{
		main();
	}
	else if(alternativaUm == 'F' || alternativaUm == 'f')
	{
		
	}
	
	//Condicionais para validação da resposta do usuário		
	if(alternativaUm == 'a' || alternativaUm == 'A')
	{
		system("cls");
		printf("\n  Você foi preso por agreção física, Seu José desenvolveu complicações e corre risco de vida e VOCÊ É O CULPADO!!!");
		_sleep(3000);		
	}
	else if(alternativaUm == 'b' || alternativaUm == 'B')
	{
		system("cls");
		printf("\n  Depois de alguns dias em isolamento, você fica desnutrido e desmaia. Seus colegas te socorrem,\n  chamam até um padre para rezar pela sua alma, pois seu estado é grave...");
		_sleep(2000);
		printf("\n  Rest in Peace Dr. %s", nomeJogador);
		_sleep(5000);
	}
	else if(alternativaUm == 'c' || alternativaUm == 'C')
	{
		system("cls");
		printf("\n  Você foi um humano civilizado, parabéns pela sua atitude!!!\n");
		_sleep(2000);
		system("color E0");
		selo[0] = 1;
		printf("\n  Selo Humano obtido");
		_sleep(5000);
	}
	else if(alternativaUm == 'd' || alternativaUm == 'D')
	{
		system("cls");
		printf("\n  Você se despediu da sua familia e, ao mesmo tempo, infectou a todos!!!\n");
		_sleep(2000);
		printf("\n  Depois de alguns dias, Dr. %s, é  encontrado em óbito!", nomeJogador);
		_sleep(5000);	
	}
	
	// Condicionais para a repetição da pergunta
	if(alternativaUm != 'c' || alternativaUm !='C')
	{
		while(vida--)
		{
			system("cls");
			printf("\n  Vidas: %d							       M - Voltar ao menu        F - Sair do jogo\n\n", vida);
			printf("\n  Você é um médico e está no combate direto ao COVID-19. Em um de seus plantões, enquanto passava pelo corredor B\n  do setor de infectados, o Seu José espirra e as goticulas caem no seu jaleco\n  O que você faria Dr. %s?\n\n", nomeJogador);
			printf("\n  (A) Você passa a mão em um pedaço de pau e bate no Seu José.\n\n  (B) Sai correndo e se tranca no banheiro e fica lá semanas.\n\n  (C) Comprimenta de longe o seu José, ensina ele a como evitar esse\n      tipo de situação, higieniza as suas mãos e locais afetatos pelo espirro.\n \n  (D) Espero o corona me pegar, me despeço da minha familia e aguardo o meu fim.");
			printf("\n\n  Selecione a alternativa: ");
			scanf(" %c", & alternativaUm);
			
			if(alternativaUm == 'M' || alternativaUm == 'm')
			{
				main();
			}
			else if(alternativaUm == 'F' || alternativaUm == 'f')
			{
				return 0;
			}
				
			if(alternativaUm == 'a' || alternativaUm == 'A')
			{
				system("cls");
				printf("\n  Você foi preso por agreção física, Seu José desenvolveu complicações e corre risco de vida e VOCÊ É O CULPADO!!!");
				_sleep(3000);		
			}
			else if(alternativaUm == 'b' || alternativaUm == 'B')
			{
				system("cls");
				printf("\n  Depois de alguns dias em isolamento, você fica desnutrido e desmaia. Seus colegas te socorrem,\n  chamam até um padre para rezar pela sua alma, pois seu estado é grave...");
				_sleep(2000);
				printf("\n  Rest in Peace Dr. %s", nomeJogador);
				_sleep(5000);
			}
			else if(alternativaUm == 'c' || alternativaUm == 'C')
			{
				system("cls");
				printf("\n  Você foi um humano civilizado, parabéns pela sua atitude!!!\n");
				_sleep(2000);
				system("color E0");
				selo[0] = 1;
				printf("\n  Selo Humano obtido");
				_sleep(5000);
			}
			else if(alternativaUm == 'd' || alternativaUm == 'D')
			{
				system("cls");
				printf("\n  Você se despediu da sua familia e, ao mesmo tempo, infectou a todos!!!\n");
				_sleep(2000);
				printf("\n  Depois de alguns dias, Dr. %s, é  encontrado em óbito!", nomeJogador);
				_sleep(5000);	
			}
		}
	}
}
//=============================================== Parte Natanael
