-- phpMyAdmin SQL Dump
-- version 4.2.12deb2+deb8u1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Aug 06, 2016 at 03:48 AM
-- Server version: 5.5.44-0+deb8u1
-- PHP Version: 5.6.20-0+deb8u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `fsLocal`
--

-- --------------------------------------------------------

--
-- Table structure for table `nodeData`
--

CREATE TABLE IF NOT EXISTS `nodeData` (
  `toe` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `nodeID` int(6) NOT NULL,
  `temp` decimal(6,3) DEFAULT NULL,
  `hum` int(5) DEFAULT NULL,
  `sensor1` decimal(6,3) DEFAULT NULL,
  `sensor2` decimal(6,3) DEFAULT NULL,
  `sensor3` decimal(6,3) DEFAULT NULL,
  `sensor4` decimal(6,3) DEFAULT NULL,
  `sensor5` decimal(6,3) DEFAULT NULL,
  `sensor6` decimal(6,3) DEFAULT NULL,
  `solarSensor` decimal(3,3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `nodeData`
--


-- --------------------------------------------------------

--
-- Table structure for table `nodeSettings`
--

CREATE TABLE IF NOT EXISTS `nodeSettings` (
  `nodeID` int(5) NOT NULL,
  `onTime` datetime NOT NULL,
  `offTime` datetime NOT NULL,
  `waterThreshold` decimal(10,0) NOT NULL,
  `masterID` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `nodeSettings`
--



-- --------------------------------------------------------

--
-- Table structure for table `nodeTypes`
--

CREATE TABLE IF NOT EXISTS `nodeTypes` (
  `modelType` varchar(10) NOT NULL,
  `fillerBot` tinyint(1) NOT NULL,
  `waterBot` tinyint(1) NOT NULL,
  `monitorBot` tinyint(1) NOT NULL,
  `numberOfSensors` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `nodes`
--

CREATE TABLE IF NOT EXISTS `nodes` (
  `serial` varchar(30) NOT NULL,
  `nodeID` int(6) NOT NULL,
  `name` varchar(30) NOT NULL,
  `location` varchar(30) NOT NULL,
  `type` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



--
-- Indexes for dumped tables
--

--
-- Indexes for table `nodeData`
--
ALTER TABLE `nodeData`
 ADD PRIMARY KEY (`toe`);

--
-- Indexes for table `nodeSettings`
--
ALTER TABLE `nodeSettings`
 ADD PRIMARY KEY (`nodeID`);

--
-- Indexes for table `nodeTypes`
--
ALTER TABLE `nodeTypes`
 ADD PRIMARY KEY (`modelType`);

--
-- Indexes for table `nodes`
--
ALTER TABLE `nodes`
 ADD PRIMARY KEY (`serial`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
