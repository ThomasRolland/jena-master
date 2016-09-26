#!/bin/sh
cd src
rm Makefile
cp Makefile_jena Makefile
echo "Ouvrir Sublim et Find in files > //sleep to sleep\n";
echo "Appuyez sur ENTREE uniquement quand vous avez termine\n";
read
make
echo ".jena compile !\n";
echo "Ouvrir Sublim et Find in files > sleep to //sleep\n";
echo "Appuyez sur ENTREE uniquement quand vous avez termine\n";
read
rm Makefile
cp Makefile_jenadev Makefile
make
echo ".jena-dev compile !\n";
echo "Voulez-vous commit les executables obtenus ?\n"
echo "Entrez : y/n";
read choix
if [ "$choix" == "y" ]; then
    echo "\nCommit to GITHUB...\n"
    cd ..
    git add jena
    git add jena-dev
    git commit -m "MAJ des executables jena et jena-dev (auto)"
    git push
    echo "\nFin.\n";
else
    echo "\nFin.\n"
    cd ..
fi