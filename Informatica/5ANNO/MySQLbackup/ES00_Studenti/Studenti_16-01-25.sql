-- MySQL dump 10.13  Distrib 8.0.40, for Linux (x86_64)
--
-- Host: localhost    Database: Studenti
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
-- Table structure for table `Corsi`
--

DROP TABLE IF EXISTS `Corsi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Corsi` (
  `codice_corso` int NOT NULL AUTO_INCREMENT,
  `nome_corso` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`codice_corso`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Corsi`
--

LOCK TABLES `Corsi` WRITE;
/*!40000 ALTER TABLE `Corsi` DISABLE KEYS */;
INSERT INTO `Corsi` VALUES (1,'Informatica'),(2,'Artistico'),(3,'Telecomunicazioni');
/*!40000 ALTER TABLE `Corsi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Materie`
--

DROP TABLE IF EXISTS `Materie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Materie` (
  `codice_materia` int NOT NULL AUTO_INCREMENT,
  `nome_materia` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`codice_materia`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Materie`
--

LOCK TABLES `Materie` WRITE;
/*!40000 ALTER TABLE `Materie` DISABLE KEYS */;
INSERT INTO `Materie` VALUES (1,'Matematica'),(2,'Italiano'),(3,'Informatica');
/*!40000 ALTER TABLE `Materie` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Studenti`
--

DROP TABLE IF EXISTS `Studenti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Studenti` (
  `matricola` int NOT NULL AUTO_INCREMENT,
  `cognome` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `data_nascita` date NOT NULL,
  `codice_corso` int DEFAULT NULL,
  `capogruppo` int NOT NULL,
  PRIMARY KEY (`matricola`),
  KEY `codice_corso` (`codice_corso`),
  CONSTRAINT `Studenti_ibfk_1` FOREIGN KEY (`codice_corso`) REFERENCES `Corsi` (`codice_corso`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Studenti`
--

LOCK TABLES `Studenti` WRITE;
/*!40000 ALTER TABLE `Studenti` DISABLE KEYS */;
INSERT INTO `Studenti` VALUES (1,'Angelico','2006-01-01',1,1),(2,'Baglì','2006-02-02',1,1),(3,'Buongallino','2006-03-03',1,3),(4,'Spinola','2006-04-04',1,3);
/*!40000 ALTER TABLE `Studenti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Valutazioni`
--

DROP TABLE IF EXISTS `Valutazioni`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Valutazioni` (
  `codice_valutazione` int NOT NULL AUTO_INCREMENT,
  `matricola` int DEFAULT NULL,
  `codice_materia` int DEFAULT NULL,
  `voto` int NOT NULL,
  `commento` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`codice_valutazione`),
  KEY `matricola` (`matricola`),
  KEY `codice_materia` (`codice_materia`),
  CONSTRAINT `Valutazioni_ibfk_1` FOREIGN KEY (`matricola`) REFERENCES `Studenti` (`matricola`) ON UPDATE CASCADE,
  CONSTRAINT `Valutazioni_ibfk_2` FOREIGN KEY (`codice_materia`) REFERENCES `Materie` (`codice_materia`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Valutazioni`
--

LOCK TABLES `Valutazioni` WRITE;
/*!40000 ALTER TABLE `Valutazioni` DISABLE KEYS */;
INSERT INTO `Valutazioni` VALUES (1,1,1,8,'COMPITO SULLE FUNZIONI'),(2,1,2,7,'VERGA'),(3,2,1,6,'COMPITO SULLE FUNZIONI'),(4,2,2,8,'VERGA'),(5,3,1,9,'COMPITO SULLE FUNZIONI'),(6,3,2,7,'VERGA'),(7,4,1,4,'COMPITO SULLE FUNZIONI'),(8,4,2,6,'VERGA');
/*!40000 ALTER TABLE `Valutazioni` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-01-16 23:30:39
