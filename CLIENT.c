/* Programme client : envoie un message à un serveur */
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include<unistd.h>
int game()
{
int sock_vers_serv ; /* sock_vers_serv utilisée pour envoyer au serveur un message
*/
struct hostent *num_ip_serv ; /* pointeur sur une structure donnant : nom, @
IP; ... du serveur */
struct sockaddr_in adr_serv ; /* adresse socket serveur*/
int lg_adr_serv; /* longueur de l’adr. la socket serveur*/
struct sockaddr_in adr_client ; /* adresse socket distante*/
int lg_adr_client; /* longueur de l’adresse de la socket client*/
char message[256] ;
/* création de la socket vers le serveur */
if ((sock_vers_serv = socket(AF_INET, SOCK_STREAM,0))==-1)
{ printf("echec création de la socket vers le serveur\n");
return -1 ;
}
/* la socket est attachée à une adresse IP et un numéro de port
(IPPORT_USERRESERVED+1) */
bzero((char *)&adr_client, sizeof(adr_serv)) ;
adr_client.sin_port = IPPORT_USERRESERVED+1 ;
adr_client.sin_addr.s_addr = INADDR_ANY ;
adr_client.sin_family =AF_INET ;
bind (sock_vers_serv, (struct sockaddr*)&adr_client, sizeof(adr_client)) ;
/* connexion au serveur*/
bzero((char *)&adr_serv, sizeof(adr_serv)) ;
if ((num_ip_serv=gethostbyname("127.0.0.1"))==NULL)
{printf(" nom de la machine serveur inconnu \n");
return -3;
}
else
{bcopy(num_ip_serv->h_addr, &adr_serv.sin_addr,num_ip_serv->h_length) ;
}
adr_serv.sin_port = IPPORT_USERRESERVED ;
adr_serv.sin_family =AF_INET ;
if (connect (sock_vers_serv, (struct sockaddr*)&adr_serv, sizeof(adr_serv))==-1)
{
printf(" echec connexion \n") ;
return -2 ;
}
printf("Donner votre message au serveur :");
scanf("%s",message);
/* émission d’un message sur la socket au moyen de la primitive write. IL existe
une autre primitive d’émission « send », celle-ci utilise un paramètre
supplémentaire « in t flag » (en dernier param.) permettant d’envoyer des données
de façon express (flag=MSG_OOB), ... */
write (sock_vers_serv,message ,sizeof(message) );
char Smot[256];char Cmot[256];
read(sock_vers_serv,Smot,sizeof(Smot)) ;
read(sock_vers_serv,Cmot,sizeof(Cmot)) ;
        if (strcmp(message, "bonjour") == 0 || strcmp(message, "salut") == 0 || strcmp(message, "bienvenue") == 0 || strcmp(message, "bonsoir") == 0) {
            printf("Serveur : %s\n", Cmot);
            printf("Serveur : Chercher le mot forme par ces lettres : [%s] !\n", Smot);
        } else {
                      printf("Serveur : %s\n", "de toute façon. ");
            printf("Serveur : Chercher le mot forme par ces lettres : [%s] !\n", Smot);
        }
//mot from server
printf("==>");
scanf("%s",Cmot);write (sock_vers_serv,Cmot ,sizeof(Cmot) );
int found;read(sock_vers_serv,&found,sizeof(found)) ;
  int i=9;char fals[256];
    if (found!=0){
read(sock_vers_serv,Smot,sizeof(Smot)) ;
printf("Serveur : %s ( ͡° ͜ʖ ͡°)\n", Smot);
    }
    else{
        while(1){
       int found01;
for (int i = 0; i < strlen(Cmot); i++) {
    found01 = 0;
    for (int j = 0; j < strlen(Smot); j++) {
        if (Cmot[i] == Smot[j]) {
            found01 = 1;
            break;
        }
    }
    if (found01) {
        sprintf(message, "La lettre ['%c'] est Vrai !", Cmot[i]);
    } else {
        sprintf(message, "La lettre ['%c'] est Faux !", Cmot[i]);
    }
    printf("Serveur : %s\n", message);
}
read(sock_vers_serv,fals,sizeof(fals)) ;
printf("Serveur : %s\n", fals);
        printf("==> ");scanf("%s",Cmot);
        write(sock_vers_serv,Cmot,sizeof(Cmot)) ;
    read(sock_vers_serv,&found,sizeof(found)) ;
        i--;

        if (found!=0){
            read(sock_vers_serv,message,sizeof(message)) ;
            printf("Serveur : %s ( ͡° ͜ʖ ͡°)\n", message);
            break;
}

           if(i<1){
read(sock_vers_serv,fals,sizeof(fals)) ;
printf("Serveur : %s ¯\\_(ツ)_/¯\n", fals);

            break;
        }
        }
    }
}

int main(){
    char answer[1],tab[1];
    printf("☞ Press enter to play! ☜");
    scanf("%c",&tab[0]);
    if(tab[0]=='\n'){
        game();
            while(1){
                printf("Rejouer ? ['Y':Oui ,'N':Non]");
                scanf(" %c",&answer[0]);
                if(answer[0]=='Y'){
                    game();
                }
                else{
                    printf("Au revoir!\n");
                    break;
                }
            }
    }

return 0;
  
};
