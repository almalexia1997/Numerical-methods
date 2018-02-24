-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Фев 24 2018 г., 18:53
-- Версия сервера: 10.1.16-MariaDB
-- Версия PHP: 5.6.24

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `student`
--

-- --------------------------------------------------------

--
-- Структура таблицы `bill`
--

CREATE TABLE `bill` (
  `bid` int(11) DEFAULT NULL,
  `num` int(11) NOT NULL,
  `bdate` date NOT NULL,
  `name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Дамп данных таблицы `bill`
--

INSERT INTO `bill` (`bid`, `num`, `bdate`, `name`) VALUES
(1, 1, '2018-02-05', 'SpaceX'),
(2, 2, '2018-02-08', 'Boing'),
(3, 3, '2018-02-12', 'SpaceX');

-- --------------------------------------------------------

--
-- Структура таблицы `bill_content`
--

CREATE TABLE `bill_content` (
  `id` int(11) NOT NULL,
  `goods` varchar(255) NOT NULL,
  `price` float NOT NULL,
  `quantity` float NOT NULL,
  `bid` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Дамп данных таблицы `bill_content`
--

INSERT INTO `bill_content` (`id`, `goods`, `price`, `quantity`, `bid`) VALUES
(1, 'Iphone 12', 70000, 10, 1),
(2, 'Ipad', 23990, 5, 2),
(3, 'MacBook', 57990, 8, 3),
(4, 'headphones', 560, 20, 1),
(5, 'column', 2990, 15, 2),
(6, 'computer mice', 450, 23, 3),
(7, 'flash cards', 999, 14, 1),
(8, 'Printer', 5000, 6, 2),
(9, 'computer', 30000, 17, 3),
(10, 'laptop', 40000, 13, 1);

-- --------------------------------------------------------

--
-- Структура таблицы `payment`
--

CREATE TABLE `payment` (
  `id` int(11) NOT NULL,
  `bid` int(11) NOT NULL,
  `pdate` date NOT NULL,
  `summa` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Дамп данных таблицы `payment`
--

INSERT INTO `payment` (`id`, `bid`, `pdate`, `summa`) VALUES
(1, 1, '2018-02-18', 700000),
(2, 2, '2018-02-19', 119950),
(3, 3, '2018-02-20', 0),
(4, 1, '2018-02-21', 11200),
(5, 2, '2018-02-22', 44850),
(6, 3, '2018-02-23', 0),
(7, 1, '2018-02-24', 13986),
(8, 2, '2018-02-25', 0),
(9, 3, '2018-02-26', 0),
(10, 1, '2018-02-27', 520000);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
