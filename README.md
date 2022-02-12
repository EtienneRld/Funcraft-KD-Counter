# Funcraft-KD-Counter

:warning: Cette application est en cours d'adaptation pour un format web :) :warning: 

Petite application console en développement permettant de compter les kills / morts durant vos parties sur **FunCraft**.

En attendant de trouver un regex pratique, voici une liste non exhaustive des pseudos pouvant causer un bug :

"par", "une", "est", "TNT", "vide", "mort", "chute", "suffocation".

Ce programme n'a pas été testé en dehors du Rush, il est possible de rencontrer des bugs en dehors de ce mode de jeu.

Si vous rencontrez des bugs ou que vous avez des questions vous pouvez me contacter sur Discord: Etienne#1230

Exemple en jeu: 

![Exemple compteur](https://i.imgur.com/ydTMxt0.png?raw=true "Exemple Compteur")

**TODO**:

- Compteur de kills ✔️
- Affichage du ratio ✔️
- Compteur d'assits :grey_question:
- Détection des équipes :grey_question: :tired_face:
- Option pour réinitialiser automatique le compteur à chaque relancement d'une partie :grey_question:

**Potentiels problèmes rencontrables**: 
- Si vous cliquez dans la console elle se fige avec le programme, appuyez sur une touche dans la console pour la réactiver :snowflake:
- Un joueur se déconnecte en pleine partie et revient avec un autre pseudo (nick ou changement premium) :japanese_goblin:
- Message de mort non répertorié (du style suffocation qui arrive très rarement) :tired_face:
- Affichage erroné des caractères unicodes dans la console :a:
- Erreur lors de l'ouverture du fichier latest.log :door:
- Driver manquant pour lancer l'application :grey_question:
- Mort non comptée :warning:
- Erreur de thread :broken_heart:
