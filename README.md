# Termi-Chat

Ce projet a pour but d'utiliser mes competences acquises en C,afin de pouvoir faire un chat sur le terminal, avec un server qui "gère" les messages, et les utilisateurs qui se connecte. 

## Installation

Un make file a été créé afin de découvrir ce qu'est un makefile, et il est fonctionnel (normalement)

```bash
git clone REPO
make all
```
Il suffit d'ouvrir un terminal avec un le serveur, et 2 autre qui lance le client.

## BUG
Lorsqu'un client se deconnecte, le server crash  
solution possible :

côté client : check si "shutdown()" coté client peut marcher. on intercepte le signal ctrl+C, et ont shutdown.
côté server : 


## differentes sources de connaissances

<https://www.youtube.com/@JacobSorber>  
<https://www.youtube.com/@codingoverflow>  
<https://www.youtube.com/watch?v=VYPcmMo1sYk&ab_channel=DominiqueLiard>  