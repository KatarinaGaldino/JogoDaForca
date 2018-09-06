#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include<stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

//Mudar cor
enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE , PINK};
    void textcolor (DOS_COLORS iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

const int animais = 5;
const int profissao = 5;
char banco1[animais][30]={     //palavras para sortear
"cachorro",
"preguica",
"doninha",
"grilo",
"hipopotamo"};

char banco2[profissao][30]={
"pistoleiro",
"engenheiro",
"medico",
"cozinheiro",
"pintor"};

char palavraSort[30];
char palavraDig[30];



int Sorteia1(){        // sorteio de palavras
    srand(time(NULL));
    return rand() % (animais);
}

int Sorteia2(){        // sorteio de palavras
    srand(time(NULL));
    return rand() % (profissao);
}


void imprimePalavraDig(int op){              //imprime a palavra digitada
	if(op==1){
		cout<<"\n Animal ";	
	}
	if(op==2)
		cout<<"\n Profissao ";
	
    cout<<"com  "<<strlen(palavraSort)<<" letras:    "; //strlen é usado pra contar os caracteres, ou quantas posições tem o vetor
    for(int i=0;i < strlen(palavraSort) ;i++){
        cout<<palavraDig[i]<<" ";
    }
}

void copiaB1(int ind){       //copia a palavra do banco para o vetor
    for(int i=0;i<30;i++){
        palavraSort[i] = banco1[ind][i];
    }
}

void copiaB2(int ind){
	for(int i=0;i<30;i++){
		palavraSort[i] =banco2[ind][i];
	}
}

void limpaPalavraDig(){   //cada posisção de palavraDig será _
 
    for(int i=0;i < strlen(palavraSort);i++){
        palavraDig[i] = '_';
    }
}

void imprimeForca(int letErro){  // imprime uma forca para cada erro
    switch(letErro){
    	
         case 0:
         
         	cout<<"\t\t\t\t\t\t\t    Vidas: "; 
         	textcolor(RED);
			 cout<<"\xFFFFFFFE \xFFFFFFFE \xFFFFFFFE \xFFFFFFFE \xFFFFFFFE \xFFFFFFFE\n";
			 textcolor(WHITE);
            cout<<" \t\t\t\t    _____ \n";
            cout<<" \t\t\t\t   |      \n";
            cout<<" \t\t\t\t   |      \n";
            cout<<" \t\t\t\t   |      \n";
            cout<<" \t\t\t\t   |      \n\n\n";
            break;
        case 1:
        	cout<<"\t\t\t\t\t\t\t    Vidas: "; 
         	textcolor(RED);
			 cout<<"\xFFFFFFFE \xFFFFFFFE \xFFFFFFFE \xFFFFFFFE \xFFFFFFFE\n";
			 textcolor(WHITE);
            cout<<" \t\t\t\t    _____ \n";
            cout<<" \t\t\t\t   |    O \n";
            cout<<" \t\t\t\t   |      \n";
            cout<<" \t\t\t\t   |      \n";
            cout<<" \t\t\t\t   |      \n\n\n";
            break;
        case 2:
        cout<<"\t\t\t\t\t\t\t    Vidas: "; 
         	textcolor(RED);
			 cout<<"\xFFFFFFFE \xFFFFFFFE \xFFFFFFFE \xFFFFFFFE \n";
			 textcolor(WHITE);
            cout<<" \t\t\t\t    _____ \n";
            cout<<" \t\t\t\t   |    O \n";
            cout<<" \t\t\t\t   |    | \n";
            cout<<" \t\t\t\t   |      \n";
            cout<<" \t\t\t\t   |      \n\n\n";
            break;
        case 3:
        	cout<<"\t\t\t\t\t\t\t    Vidas: "; 
         	textcolor(RED);
			 cout<<"\xFFFFFFFE \xFFFFFFFE \xFFFFFFFE\n";
			 textcolor(WHITE);
            cout<<" \t\t\t\t    _____ \n";
            cout<<" \t\t\t\t   |    O \n";
            cout<<" \t\t\t\t   |   /| \n";
            cout<<" \t\t\t\t   |      \n";
            cout<<" \t\t\t\t   |      \n\n\n";
            break;
        case 4:
        	cout<<"\t\t\t\t\t\t\t    Vidas: "; 
         	textcolor(RED);
			 cout<<"\xFFFFFFFE \xFFFFFFFE\n";
			 textcolor(WHITE);
            cout<<" \t\t\t\t    _____ \n";
            cout<<" \t\t\t\t   |    O \n";
            cout<<" \t\t\t\t   |   /|\x5c\n";
            cout<<" \t\t\t\t   |      \n";
            cout<<" \t\t\t\t   |      \n\n\n";
            break;
        case 5:
        cout<<"\t\t\t\t\t\t\t    Vidas: "; 
         	textcolor(RED);
			 cout<<"\xFFFFFFFE \n";
			 textcolor(WHITE);
            cout<<" \t\t\t\t    _____ \n";
            cout<<" \t\t\t\t   |    O \n";
            cout<<" \t\t\t\t   |   /|\x5c\n";
            cout<<" \t\t\t\t   |   /  \n";
            cout<<" \t\t\t\t   |      \n\n\n";
            break;
        case 6:
            
            cout<<" \t\t\t\t    _____ \n";
            cout<<" \t\t\t\t   |    O \n";
            cout<<" \t\t\t\t   |   /|\x5c\n";
            cout<<" \t\t\t\t   |   / \x5c\n";
            cout<<" \t\t\t\t   |       \n\n\n";
            break;
    }
}

bool verificaLetra(char letra, char vetor[26]){      //testa as letras em cada vetor
    for(int i=0;i<strlen(vetor);i++){
        if(letra==vetor[i]){
            return true;
        }
    }
    return false;
}

void substitui(char letra){       					// substitui cada letra no seu lugar
    for(int i=0;i<strlen(palavraSort);i++){
        if(palavraSort[i]==letra){
            palavraDig[i] = letra;
        }
    }

}

void imprimeLetDig(char letras[], int tam){   // imprime as letras que já foram digitadas
    cout<<"\n\n Letras digitadas: ";
    for(int i=0;i < tam ;i++){
        cout<<letras[i]<<", ";
    }
    cout<<"\n";
}

bool palavraCompleta(){							//verifica se a palavra está certa ou errada
	for (int i=0; i<strlen(palavraSort); i++){
		if(palavraDig[i]=='_'){
			return false;
		}
	}
	return true;
}

void jogoDaForca(){
		cout<<"       \t\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout<<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n";
		cout<<"       \t\t\t\xba                                \xba\n";
		cout<<"  \t\t\t\xba          Jogo da Forca         \xba\n";
		cout<<"       \t\t\t\xba                                \xba\n";
		cout<<"       \t\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout<<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n";
	
}




main(void){
	int op;
	jogoDaForca();

	
    cout<<"\n       \t\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MENU \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n";
		cout<<"       \t\t\t\xba                               \xba\n";
		cout<<"       \t\t\t\xba          Modalidades:         \xba\n";
		cout<<"       \t\t\t\xba          1-Animais            \xba\n";
		cout<<"       \t\t\t\xba          2-Profissao          \xba \n";	
		cout<<"       \t\t\t\xba                               \xba\n";
		cout<<"       \t\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
	
	    cout<<"\n       \t\t\tOpcao Escolhida_";
		cin>>op;



if(op == 1){
	int indPalavra1 = Sorteia1(); //Sortear uma palavra 
    	copiaB1(indPalavra1);	
}
else if(op == 2){
	int indPalavra2 = Sorteia2();
    	copiaB2(indPalavra2);	
}
else{

cout<<"op invalida";
		system("PAUSE");
		return(0);
}
    limpaPalavraDig(); // limpa o vetor da palavra digitada

    int contLetDig=0;      // conta letras digitadas

    int contErros=0;      // conta erros

    char letrasDigitadas[26]; // letras do alfabeto

    char letra;

     while(contErros<=6){
     	
        system("cls");
        jogoDaForca();
       
    
		imprimeForca(contErros);
		imprimePalavraDig(op);
        imprimeLetDig(letrasDigitadas,contLetDig);
        
        cout<<"\n";
        cout<<" Digite uma letra: ";
        cin>>letra;
        letra = tolower(letra); // tolower para não confundir maiúsculas e minusculas
        
    
        if(verificaLetra(letra,letrasDigitadas)){
            cout<<"Letra ja foi digitada! Tente novamente!\n\n";
            
        }
		else{
            letrasDigitadas[contLetDig] = letra;
            contLetDig++;

            if(verificaLetra(letra,palavraSort)){
                substitui(letra);
            }else{
                cout<<"\n Letra incorreta! Tente novamente\n\n";
                contErros++;
                system("pause>>null");
                
                
                

            }
        }
        
        if(contErros>=6){
        	system("cls");
        	jogoDaForca();
        	cout<<"\n\n\n\n\a\t\t\t       Perdeu Miseravel!\n\n";
        	cout<<" \t\t\t\t   _____ \n";
            cout<<" \t\t\t\t  |    O \n";
            cout<<" \t\t\t\t  |   /|\\\n";
            cout<<" \t\t\t\t  |   / \\\n";
            cout<<" \t\t\t\t  |       \n\n";
        	
        	cout<<"\t\t     Nao fique triste, tente novamente!\n\n";
        	cout<<"\t\t          Pressione Enter para sair";
        	system("pause>>null");
            return 0;
		}
		if (palavraCompleta()){
			cout<<"\n\n\n\n\a \t\t\t\tGanhou Miseravel!\n\n";
			cout<<"\t\t          Pressione Enter para sair";
			system("pause>>null");
			return 0;
		
		}
    } 

}

