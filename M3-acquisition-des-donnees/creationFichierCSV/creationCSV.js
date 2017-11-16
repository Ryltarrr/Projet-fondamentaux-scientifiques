// petite boucle permettant de créer des données
// au format CSV pour tester le module 4
for (let i = 100; i <= 5000; i += 100) {
  let a = Math.round((Math.random() * 55 + 55)*100) / 100;
  console.log(i+";"+a);
}
