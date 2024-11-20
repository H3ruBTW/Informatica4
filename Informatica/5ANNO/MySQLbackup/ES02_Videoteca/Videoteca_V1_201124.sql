-- MySQL dump 10.13  Distrib 8.0.40, for Linux (x86_64)
--
-- Host: localhost    Database: Videoteca
-- ------------------------------------------------------
-- Server version	8.0.40-0ubuntu0.22.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Attore`
--

DROP TABLE IF EXISTS `Attore`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Attore` (
  `id_attore` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `cognome` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `data_nascita` date NOT NULL,
  PRIMARY KEY (`id_attore`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Attore`
--

LOCK TABLES `Attore` WRITE;
/*!40000 ALTER TABLE `Attore` DISABLE KEYS */;
INSERT INTO `Attore` VALUES (1,'Cillian','Murphy','1976-05-25'),(2,'Tom','Conti','1941-11-22'),(3,'Matthew','McConaughey','1969-11-04'),(4,'Anne','Hathaway','1982-11-12');
/*!40000 ALTER TABLE `Attore` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Attori_Videocassette`
--

DROP TABLE IF EXISTS `Attori_Videocassette`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Attori_Videocassette` (
  `id_attori_videocassette` int NOT NULL AUTO_INCREMENT,
  `id_attore` int NOT NULL,
  `id_videocassetta` int NOT NULL,
  `personaggio` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`id_attori_videocassette`),
  KEY `id_attore` (`id_attore`),
  KEY `id_videocassetta` (`id_videocassetta`),
  CONSTRAINT `Attori_Videocassette_ibfk_1` FOREIGN KEY (`id_attore`) REFERENCES `Attore` (`id_attore`),
  CONSTRAINT `Attori_Videocassette_ibfk_2` FOREIGN KEY (`id_videocassetta`) REFERENCES `Videocassetta` (`id_videocassetta`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Attori_Videocassette`
--

LOCK TABLES `Attori_Videocassette` WRITE;
/*!40000 ALTER TABLE `Attori_Videocassette` DISABLE KEYS */;
INSERT INTO `Attori_Videocassette` VALUES (1,1,1,'Robert J. Oppenheimer'),(2,2,1,'Albert Einstein'),(3,3,2,'Joseph Cooper'),(4,4,2,'Amelia Brand');
/*!40000 ALTER TABLE `Attori_Videocassette` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Cliente`
--

DROP TABLE IF EXISTS `Cliente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Cliente` (
  `id_tessera` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `cognome` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `data_nascita` date NOT NULL,
  PRIMARY KEY (`id_tessera`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Cliente`
--

LOCK TABLES `Cliente` WRITE;
/*!40000 ALTER TABLE `Cliente` DISABLE KEYS */;
INSERT INTO `Cliente` VALUES (1,'Mario','Rossi','1987-09-11'),(2,'Daniele','Voda','1965-02-01');
/*!40000 ALTER TABLE `Cliente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Formato`
--

DROP TABLE IF EXISTS `Formato`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Formato` (
  `id_formato` int NOT NULL AUTO_INCREMENT,
  `tipo` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`id_formato`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Formato`
--

LOCK TABLES `Formato` WRITE;
/*!40000 ALTER TABLE `Formato` DISABLE KEYS */;
INSERT INTO `Formato` VALUES (1,'CD'),(2,'DVD'),(3,'VIDEOCASSETTA');
/*!40000 ALTER TABLE `Formato` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Genere`
--

DROP TABLE IF EXISTS `Genere`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Genere` (
  `id_genere` int NOT NULL AUTO_INCREMENT,
  `nome_genere` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`id_genere`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Genere`
--

LOCK TABLES `Genere` WRITE;
/*!40000 ALTER TABLE `Genere` DISABLE KEYS */;
INSERT INTO `Genere` VALUES (1,'biografico'),(2,'drammatico'),(3,'thriller'),(4,'storico'),(5,'fantascienza'),(6,'avventura');
/*!40000 ALTER TABLE `Genere` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Generi_Videocassette`
--

DROP TABLE IF EXISTS `Generi_Videocassette`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Generi_Videocassette` (
  `id_generi_videocassette` int NOT NULL AUTO_INCREMENT,
  `id_genere` int NOT NULL,
  `id_videocassetta` int NOT NULL,
  PRIMARY KEY (`id_generi_videocassette`),
  KEY `id_genere` (`id_genere`),
  KEY `id_videocassetta` (`id_videocassetta`),
  CONSTRAINT `Generi_Videocassette_ibfk_1` FOREIGN KEY (`id_genere`) REFERENCES `Genere` (`id_genere`),
  CONSTRAINT `Generi_Videocassette_ibfk_2` FOREIGN KEY (`id_videocassetta`) REFERENCES `Videocassetta` (`id_videocassetta`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Generi_Videocassette`
--

LOCK TABLES `Generi_Videocassette` WRITE;
/*!40000 ALTER TABLE `Generi_Videocassette` DISABLE KEYS */;
INSERT INTO `Generi_Videocassette` VALUES (1,1,1),(2,2,1),(3,3,1),(4,4,1),(5,5,2),(6,6,2),(7,2,2);
/*!40000 ALTER TABLE `Generi_Videocassette` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Pagamento`
--

DROP TABLE IF EXISTS `Pagamento`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Pagamento` (
  `id_pagamento` int NOT NULL AUTO_INCREMENT,
  `id_prestito` int NOT NULL,
  `prezzo` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`id_pagamento`),
  KEY `id_prestito` (`id_prestito`),
  CONSTRAINT `Pagamento_ibfk_1` FOREIGN KEY (`id_prestito`) REFERENCES `Prestito` (`id_prestito`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Pagamento`
--

LOCK TABLES `Pagamento` WRITE;
/*!40000 ALTER TABLE `Pagamento` DISABLE KEYS */;
INSERT INTO `Pagamento` VALUES (1,1,'5,79€'),(2,2,'3,00€');
/*!40000 ALTER TABLE `Pagamento` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Prestito`
--

DROP TABLE IF EXISTS `Prestito`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Prestito` (
  `id_prestito` int NOT NULL AUTO_INCREMENT,
  `id_tessera` int DEFAULT NULL,
  `id_videocassetta` int DEFAULT NULL,
  `data_inizio` date NOT NULL,
  `data_fine` date NOT NULL,
  PRIMARY KEY (`id_prestito`),
  KEY `id_tessera` (`id_tessera`),
  KEY `id_videocassetta` (`id_videocassetta`),
  CONSTRAINT `Prestito_ibfk_1` FOREIGN KEY (`id_tessera`) REFERENCES `Cliente` (`id_tessera`) ON DELETE SET NULL,
  CONSTRAINT `Prestito_ibfk_2` FOREIGN KEY (`id_videocassetta`) REFERENCES `Videocassetta` (`id_videocassetta`) ON DELETE SET NULL
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Prestito`
--

LOCK TABLES `Prestito` WRITE;
/*!40000 ALTER TABLE `Prestito` DISABLE KEYS */;
INSERT INTO `Prestito` VALUES (1,1,2,'2024-11-20','2025-01-20'),(2,2,1,'2024-11-20','2024-12-20');
/*!40000 ALTER TABLE `Prestito` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Regista`
--

DROP TABLE IF EXISTS `Regista`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Regista` (
  `id_regista` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `cognome` varchar(30) COLLATE utf8mb4_unicode_ci NOT NULL,
  `data_nascita` date NOT NULL,
  PRIMARY KEY (`id_regista`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Regista`
--

LOCK TABLES `Regista` WRITE;
/*!40000 ALTER TABLE `Regista` DISABLE KEYS */;
INSERT INTO `Regista` VALUES (1,'Christopher','Nolan','1970-07-30');
/*!40000 ALTER TABLE `Regista` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Registi_Videocassette`
--

DROP TABLE IF EXISTS `Registi_Videocassette`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Registi_Videocassette` (
  `id_registi_videocassette` int NOT NULL AUTO_INCREMENT,
  `id_regista` int NOT NULL,
  `id_videocassetta` int NOT NULL,
  PRIMARY KEY (`id_registi_videocassette`),
  KEY `id_regista` (`id_regista`),
  KEY `id_videocassetta` (`id_videocassetta`),
  CONSTRAINT `Registi_Videocassette_ibfk_1` FOREIGN KEY (`id_regista`) REFERENCES `Regista` (`id_regista`),
  CONSTRAINT `Registi_Videocassette_ibfk_2` FOREIGN KEY (`id_videocassetta`) REFERENCES `Videocassetta` (`id_videocassetta`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Registi_Videocassette`
--

LOCK TABLES `Registi_Videocassette` WRITE;
/*!40000 ALTER TABLE `Registi_Videocassette` DISABLE KEYS */;
INSERT INTO `Registi_Videocassette` VALUES (1,1,1),(2,1,2);
/*!40000 ALTER TABLE `Registi_Videocassette` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Videocassetta`
--

DROP TABLE IF EXISTS `Videocassetta`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Videocassetta` (
  `id_videocassetta` int NOT NULL AUTO_INCREMENT,
  `id_formato` int NOT NULL,
  `titolo` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `durata` varchar(10) COLLATE utf8mb4_unicode_ci NOT NULL,
  `data_uscita` date NOT NULL,
  PRIMARY KEY (`id_videocassetta`),
  KEY `id_formato` (`id_formato`),
  CONSTRAINT `Videocassetta_ibfk_1` FOREIGN KEY (`id_formato`) REFERENCES `Formato` (`id_formato`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Videocassetta`
--

LOCK TABLES `Videocassetta` WRITE;
/*!40000 ALTER TABLE `Videocassetta` DISABLE KEYS */;
INSERT INTO `Videocassetta` VALUES (1,2,'Oppenheimer','180 min','2023-07-11'),(2,2,'Interstellar','169 min','2014-11-05');
/*!40000 ALTER TABLE `Videocassetta` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-11-20 15:53:28
