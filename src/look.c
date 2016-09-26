#include "fonctions.h"

void		look()
{
  if(SALLE == 1)
    {
      my_putstr("Visiblement, je suis dans le poste de pilotage du vaisseau.\nTout est sans dessus-dessous, les appareils sont tous endommagés.\n");
      my_putstr("La console centrale parait en bon état, il faudrait du j'y jette un oeil.\n");
      my_putstr("J'espère que le crash n'a pas trop endommagé le reste de l'ICARUS...\n");
      my_putstr("Pour l'instant, ma meilleure chance de survie est de faire décoller ce vieux coucou...\n\n");
    }
  if(SALLE == 2)
    {
      my_putstr("Ce sont mes quartiers... Pourtant rien ne me revient... Je devrais peut être fouiller la pièce pour obtenir des informations.\n\n");
    }
  if(SALLE == 3)
    {
      my_putstr("On dirait un sas. Il y a 3 portes : une à l'ouest, une au nord, et une à l'est. Elles sont toutes verrouillées.\n");
      my_putstr("J'ai l'embarras du choix. Alors, quelle porte essayons-nous ?\n\n");
    }
  if(SALLE == 4)
    {
      my_putstr("Des armes, des munitions... Ce doit être l'armurerie ! Je comprends maintenant pourquoi il fallait une carte d'accès de haut niveau pour rentrer ici.\n");
      my_putstr("Etre commandant a ses avantages je suppose ! Je ferai mieux de m'équiper.\n\n");
    }
  if(SALLE == 5)
    {
      my_putstr("Je suis dans un long couloir. Je vois des portes, qui donnent sur de petites pièces. Il y a des noms sur les portes : COLAS, ANDERSON,...\n");
      my_putstr("Ce sont des cabines. A mon avis, je me trouve dans les quartiers de l'équipage. Je ne sais pas si le désordre est dû au crash ou aux membres de l'équipage...\n\n");
    }
  if(SALLE == 6)
    {
      my_putstr("Je commence à avoir mal aux pieds... Je vous ai déja dis ce que ma mère disait des mes pieds ?\n");
      my_putstr("Je peux emprunter le couloir de gauche, ou celui de droite, pardon, les couloirs à l'est ou à l'ouest. J'oublie parfois que vous êtes loin d'ici...\n");
      my_putstr("Pourtant j'ai parfois l'impression que vous êtes avec moi, tous les deux dans cette galère inter-galactique...\n");
      my_putstr("Excusez-moi, qu'est-ce que je disais déja ?\n");
      my_putstr("Ah oui, je peux aller à l'est, à l'ouest ! Au nord, la porte semble verouillée, je vois un lecteur de carte sur le mur.\n\n");
    }
  if(SALLE == 7)
    {
      my_putstr("\nMe voilà dans un couloir avec des portes... Je peux lire des noms sur les portes : DAVIS, CLAY,...\n");
      my_putstr("Chaque porte mène à une petite cabine. Tout est bien rangé, j'ai vu quelques affaires féminines.\n");
      my_putstr("Je dois être dans les quartiers des femmes.\n");
      if (DIAG_S03A02 == 0)
         {
           my_putstr("Etrange, je ne vois pas de cabine à mon nom...\n");
         }
      my_putstr("\n");
    }
  if(SALLE == 8)
    {
      my_putstr("\n\nJe suis dans l'infirmerie. Le sol est couvert de sang.\n");
      if(CARTE_ACCES == 0)
	    {
	      my_putstr("Si je n'etais pas autant ecoeurée, je fouillerai peut être le corps du Sergent Colas.\n\n");
	    }
      else
	    {
	      my_putstr("Il y a une porte derrière, peut-être une sorte de réserve ?\n\n");
	    }
    }
  if(SALLE == 9)
    {
      my_putstr("\nJe suis dans la grande salle. Il m'est difficile de rester là, la vision de ces cadavres est insupportable...\n\n");
    }
  if(SALLE == 10)
    {
      my_putstr("J'entre dans ce qui ressemble à un laboratoire. Tout est blanc, il y a des étagères remplies de produits et de matériel en verre.\n");
      my_putstr("Je vois de grandes machines dans le fond, mais j'ignore à quoi elles peuvent bien servir...\n\n");
    }
  if(SALLE == 11)
    {
      my_putstr("\nJe suis dans la réserve de l'infirmerie. La plupart des appareils qui sont là sont endommagés, dommage.\n");
      my_putstr("\nJ'espère trouver quelques medicaments dans ce bazar...\n\n");
    }
  if(SALLE == 12)
    {
      my_putstr("\nJe suis dans un grand couloir. il n' a rien a faire ici a part s'assoir et pleurer...");
      my_putstr("\nMais ne vous inquiétez pas je ne vais pas mettre à pleurer... Pas tout de suite.\n");
      my_putstr("D'ici je peux aller dans toutes les directions.\n\n");
    }
  if(SALLE == 13)
    {
      my_putstr("Je suis arrivé dans un grand sas peu éclairé. La seule source de lumière est un néon bleuté au plafond, qui donne une athmosphère... disons assez \"film d'horreur\" !\n");
      my_putstr("J'ai entendu du bruit ! Des bruits qui venaient... du mur ?\n");
      my_putstr("Là, je commence vraiment à flipper !\n");
      my_putstr("Oh je sais ce que vous vous dites : \"Elle débloque cette pauvre fille, un petit bruit et pouf, elle tombe dans les pommes !\"\n");
      my_putstr("J'aimerai bien vous voir à ma place ! Ce n'est pas vous qui risquez à tout moment de vous faire dévorer à tout moment par...\n");
      my_putstr("...Je ne sais pas, un alien fluorescent, ou une bête cosmique enragée, hein !\n\n");
    }
  if(SALLE == 14)
    {
      my_putstr("J'entre dans une pièce minuscule, face à moi : une épaisse porte blindée.\n");
      my_putstr("Il y a une baie vitrée sur le côté de la pièce : je peux y voir... Oh mon dieu !\n");
      my_putstr("(Enfin, si un dieu-des-aventuriers-de-l'espace-qui-se-sont-crashés-au-milieu-de-nulle-part existe !)\n");
    my_putstr("A travers la baie vitrée je peux voir en contrebas un immense hangar, et quelques petits vaisseaux en piteux état...\n");
    my_putstr("L'un d'eux a surement dû exploser vu les traces noires au sol tout autour...\n");
 my_putstr("Mais ce n'est pas ça qui m'a interpellé ! Il y a une énorme brèche dans la coque !\n");
 my_putstr("Le trou fait au moins 3 mètres de diamètre ! Au moins.\n");
 my_putstr("J'aperçois aussi la porte de sortie du hangar : fermée.\n");
 my_putstr("Que dois-je faire, passer la porte blindée et descendre voir les dégats au hangar, ou faire demi-tour ?\n\n");
    }
  if(SALLE == 15)
    {
      my_putstr("Je suis dans le hangar, au niveau des vaisseaux endommagés. J'en compte 3 : l'un est completement retourné, l'aile brisée.\n");
      my_putstr("Le second tient encore sur ses roues, il ne semble pas avoir trop souffert du crash.\n");
      my_putstr("Le dernier est celui que j'ai aperçu plus tôt : totalement carbonisé.\n\n");
    }
  if(SALLE == 16)
    {
      my_putstr("Je suis au fond du hangar, au niveau de la brèche dans la coque. Ce n'est pas beau à voir.\n");
      my_putstr("Le trou est bien trop haut pour que j'y accède.\n");
      my_putstr("Oh oh. OH, OH !\n");
      my_putstr("Méga problème droit devant ! Du genre : énorme monstre-gluant-dangereux à douze heures !\n");
      my_putstr("Et surtout du genre qui bloque la sortie du hangar !\n");
      my_putstr("Berk, on dirait une grosse larve mutante qui... Oh là là !\n");
      my_putstr("Qui pond des petites créatures qui grouillent dans toutes les directions !\n");
      my_putstr("Ils ont grignotté une partie de la coque, des tuyaux...\n");
      my_putstr("J'en vois qui s'engouffrent dans les tuyaux et les canalisations du vaisseau !\n");
      my_putstr("Si je veux sortir par la porte du hangar, il va falloir se débarrasser de la larve géante et trouver un moyen d'ouvrir la porte.\n");
      my_putstr("Ou alors, je fais VITE demi-tour et je trouve un autre moyen de sortir de ce vaisseau !\n");
      my_putstr("Je vous avoue que j'ai une préférence pour la seconde option !\n");
      my_putstr("A vous de choisir : au sud, combat en perpective, au nord, je prends mes jambes à mon cou !\n\n");
    }
  if(SALLE == 17)
    {
      my_putstr("Encore un couloir... Il n'y a donc pas d'ascensceur ou de téléporteur à bord ?\n");
      if (DIAG_S03A02 == 0)
         {
           my_putstr("Si je trouve le commandant, je lui toucherai un mot ou deux sur l'agencement de son vaisseau !\n");
         }
      my_putstr("Je peux continuer à aller vers le sud, ou rebrousser chemin vers le nord.\n\n");
    }
  if(SALLE == 18)
    {
      my_putstr("Tout est différent ici... Les murs sont gris, et couverts de tuyaux et de cables en tous genres...\n");
      my_putstr("Il fait aussi beaucoup plus chaud... On doit se rapprocher du réacteur du vaisseau.\n");
      my_putstr("J'espère ne pas finir grillée par la chaleur ou les radiations...\n\n");
    }
  if(SALLE == 19)
    {
      my_putstr("J'avais raison, je vois le réacteur d'ici ! Plusieurs petits hublots donnent une vue imprenable sur le coeur du vaisseau.\n");
      my_putstr("Ce n'est pas du tout comme je l'immaginai...\n");
      my_putstr("Pour vous décrire ça simplement, tous les tuyaux que j'ai rencontré sur ma route passent à travers le mur et se rejoignent au centre de la salle du réacteur.\n");
      my_putstr("Au-dessus ces cables se forme une gigantesque boule d'énergie... C'est magnifique. Et potentiellement meurtrier s'il y a une défaillance !\n\n");
    }
  if(SALLE == 20)
    {
      my_putstr("#Fonction manquante : texte en cours d'écriture.\n\n");
    }
  if(SALLE == 21)
    {
      my_putstr("#Fonction manquante : texte en cours d'écriture.\n\n");
    }
  if(SALLE == 22)
    {
      my_putstr("#Fonction manquante : texte en cours d'écriture.\n\n");
    }
  if(SALLE == 23)
    {
      my_putstr("Ah, enfin une pièce digne d'intérêt ! Des étagères pleins de boites, de rations de survies, de petit matériel en tout genre !\n");
      my_putstr("Des barres hypercaloriques au chocolat ! Parfait, voilà de quoi me remplir l'estomac !\n");
      my_putstr("En fouillant un peu, je suis sure de trouver des choses interessantes !\n\n");
    }
  if(SALLE == 24)
    {
      my_putstr("Je suis dans la deuxième partie de la réserve. Cette pièce contient plus de cartons, et moins de nourriture, donc : sans intérêt !\n\n");
    }
}
