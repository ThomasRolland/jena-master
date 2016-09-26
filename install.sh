git clone "https://github.com/nextjoey/jena.git" JENA
echo "rm install.sh" >> jena.sh
echo "cd JENA\n" >> jena.sh
echo "git pull\n" >> jena.sh
echo "./jena" >> jena.sh
cd JENA
./jena