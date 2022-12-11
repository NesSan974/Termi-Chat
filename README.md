# Termi-Chat

Ce projet a pour but d'utiliser mes competences acquises en C,afin de pouvoir faire un chat sur le terminal, avec un server qui "gère" les messages, et les utilisateurs qui se connecte. 

## Installation

Un make file a été créé afin de découvrir ce qu'est un makefile, et il est fonctionnel (normalement)

```bash
git clone REPO
make all
```
Il suffit d'ouvrir un terminal avec un le serveur, et 2 autre qui lance le client.

## Les soucis



n'ayant pas mis de mutex, des soucis peuvent probalement arriver si des thread veulent ecrire dans la list allClient  
notemment :  
lorsque 2 clients se connecte en meme temps  
Si il y'a une deconnexion et une connexion en même temps
lorsque 2 clients se déconnecte en meme temps  


## TODO

clean_up le code
detecter le flag ctrl+c et shutdown tout les sockets de la liste.  

### Long terme

creation de connexion securisé avec SSL.  
Creation de liste d'amis  
creation de lobby  


## differentes sources de connaissances

<https://www.youtube.com/@JacobSorber>  
<https://www.youtube.com/@codingoverflow>  
<https://www.youtube.com/watch?v=VYPcmMo1sYk&ab_channel=DominiqueLiard>  

### SSL
https://wiki.openssl.org/index.php/Simple_TLS_Server  
https://stackoverflow.com/questions/7698488/turn-a-simple-socket-into-an-ssl-socket  
https://aticleworld.com/ssl-server-client-using-openssl-in-c/    
https://fm4dd.com/openssl/sslconnect.shtm  
