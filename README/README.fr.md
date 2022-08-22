# <u>PGQR</u>
Une extension PostgreSQL pour générer des QR codes.

## Présentation

Ce projet ajoute deux fonctionnalités au générateur de QR codes de ce dépôt https://github.com/swex/QR-Image-embedded: <br />
1. Construction de bitmaps monochromes en mémoire (1 bit par pixel).<br />
2. Empaquettage de l'ensemble en tant qu'extension PostgreSQL.<br />

## Installation

Ce projet a été compilé et testé avec succès avec la version 11 de PostgreSQL sur une distribution Linux. Commandes à taper dans le terminal pour compiler l'extension :
> \$ make clean
> \$ make
> \$ make install<br />

Après une compilation réussie, installez cette extension dans votre environnement PostgreSQL en tapant la commande :
> create extension pgqr<br />

## Fonctionnalités

La fonction <b>pgqr</b> prend obligatoirement 4 variables en paramètres :
1. La variable <b>t</b> de type <i>text</i> : il s'agit du texte à encoder ;
2. La variable <b>correction_level</b> de type <i>integer</i> : valeurs allant de 0 à 3 ;
3. La variable <b>model_number</b> de type <i>integer</i> : valeurs allant de 0 à 2 ;
4. La variable <b>scale</b> de type <i>integer</i> : il s'agit du nombre de pixels par point (plus ce nombre sera grand et plus la taille du QR sera grande, même pour une toute petite chaîne de caractères encodée. Taille recommandé : 4. À adapter selon les préférences).

## Exemple

Si vous créez un QR code avec la commande SQL :
> select pgqr('QR Code with PostgreSQL', 0, 0, 4);

<br />

Alors vous obtiendrez des données binaires. Pour pouvoir afficher ces données binaires sous la forme d'un QR, il vous suffit de les insérer dans une balise HTML <b>\<img></b> comme ceci :
> \<img src="data:image/png;base64,<b>xxxxx</b>" alt="QR Code" />

Remplacez les <b>xxxxx</b> par vos données binaires, qui de préférence, seront réceptionnez de PostgreSQL sous la forme d'une variable (par exemple, une variable dans un JSON de réponse d'une API PostgREST). Cela fonctionne très bien avec React côté Front pour réceptionner les données binaires.

Ainsi, vous devriez obtenir ce résultat :

<img src="https://abdulyadi.files.wordpress.com/2019/01/image-1.png?w=545">

## Notes

Il semblerait, tel qu'évoqué dans cet <a href="https://github.com/AbdulYadi/pgqr/issues/1"><i>issue</i></a>, que l'extension ne gère pas (encore) l'encodage des caractères cyrilliques (et peut-être même d'autres jeux de caractères). Origine du problème à confirmer.