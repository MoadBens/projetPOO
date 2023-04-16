BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "Test" (
	"ID"	INTEGER NOT NULL UNIQUE,
	"Nom"	TEXT NOT NULL,
	"Prenom"	TEXT NOT NULL,
	"Niveau"	INTEGER NOT NULL,
	"Mdp"	TEXT NOT NULL,
	PRIMARY KEY("ID")
);
INSERT INTO "Test" ("ID","Nom","Prenom","Niveau","Mdp") VALUES (1,'Yahyaoui','Mehdi',1,'Test'),
 (2,'Benslimane','Moad',1,'Hello');
COMMIT;
