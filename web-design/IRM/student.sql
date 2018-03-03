-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Мар 02 2018 г., 17:04
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
-- Структура таблицы `library`
--

CREATE TABLE `library` (
  `id` int(11) NOT NULL,
  `name_book` varchar(100) NOT NULL,
  `author` varchar(250) NOT NULL,
  `ldate` int(11) NOT NULL,
  `annotation` text NOT NULL,
  `theme` int(11) NOT NULL,
  `issued` int(11) DEFAULT NULL,
  `name_file` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Дамп данных таблицы `library`
--

INSERT INTO `library` (`id`, `name_book`, `author`, `ldate`, `annotation`, `theme`, `issued`, `name_file`) VALUES
(1, 'Game of Thrones', 'George Martin', 1996, 'Long ago, in a time forgotten, a preternatural event threw the seasons out of balance. In a land where summers can last decades and winters a lifetime, trouble is brewing. The cold is returning, and in the frozen wastes to the north of Winterfell, sinister and supernatural forces are massing beyond the kingdom’s protective Wall. At the center of the conflict lie the Starks of Winterfell, a family as harsh and unyielding as the land they were born to. Sweeping from a land of brutal cold to a distant summertime kingdom of epicurean plenty, here is a tale of lords and ladies, soldiers and sorcerers, assassins and bastards, who come together in a time of grim omens.\r\n\r\nHere an enigmatic band of warriors bear swords of no human metal; a tribe of fierce wildlings carry men off into madness; a cruel young dragon prince barters his sister to win back his throne; and a determined woman undertakes the most treacherous of journeys. Amid plots and counterplots, tragedy and betrayal, victory and terror, the fate of the Starks, their allies, and their enemies hangs perilously in the balance, as each endeavors to win that deadliest of conflicts: the game of thrones.', 1, NULL, 'gameothrones.jpg'),
(2, 'Empire of Angels', 'Bernard Werber', 2000, 'Michael Pinson has passed on. For this hero of Thanatonautes, the final hour has struck. He finds himself facing his judges and obliged to make a choice : to come back to earth as an Initiated Master or to escape the reincarnation cycle.\r\n\r\nFrom a reincarnated human being, he moves on to become an angel. But in his new guise of guardian angel, Michael discovers that watching over human beings and granting their wishes - even the most absurd - is no piece of cake. More like a taste of Hell.\r\n\r\nThis insatiable explorer has retained his taste for adventure from his previous life. Angel in rebellion, he sets himself an aim : to discover what lies beyond the beyond, and after that. Perhaps, by breaking into the forbidden circle, he''ll penetrate the secrets of the Gods.', 2, 0, 'empireofangels.jpg'),
(3, 'A Brief History of Time', 'Stephen Hawking', 1998, 'In A Brief History of Time, Stephen Hawking attempts to explain a range of subjects in cosmology, including the Big Bang, black holes and light cones, to the nonspecialist reader. His main goal is to give an overview of the subject, but he also attempts to explain some complex mathematics. In the 1996 edition of the book and subsequent editions, Hawking discusses the possibility of time travel and wormholes and explores the possibility of having a universe without a quantum singularity at the beginning of time.', 3, NULL, 'briefhistoryoftime.jpg'),
(4, 'War and Peace', 'Leo Tolstoy', 1869, 'The novel begins in July 1805 in Saint Petersburg, at a soirée given by Anna Pavlovna Scherer—the maid of honour and confidante to the dowager Empress Maria Feodorovna. Many of the main characters are introduced as they enter the salon. Pierre (Pyotr Kirilovich) Bezukhov is the illegitimate son of a wealthy count, who is dying after a series of strokes. Pierre is about to become embroiled in a struggle for his inheritance. Educated abroad at his father''s expense following his mother''s death, Pierre is kindhearted but socially awkward, and finds it difficult to integrate into Petersburg society. It is known to everyone at the soirée that Pierre is his father''s favorite of all the old count’s illegitimate progeny.', 2, 0, 'warandpeace.jpg'),
(5, 'The Stars Are Cold Toys', 'Sergey Lukianenko', 1997, 'During a usual trading flight Pyotr found a Counter on his craft who called himself Karel and, most importantly, made it through the jump unhurt (ironically, the alien accomplished this by going into a self-induced coma caused by division by zero). Standing orders require Pyotr to destroy the ship and all evidence of the alien''s survival, as this would eliminate the Conclave''s need in Humanity. The alien requested an informal meeting with Andrey Khrumov — Pyotr''s grandfather and a known political scientist, also a great patriot of Humanity, biased against the Strong races.\r\n\r\nA fleet of Alary has captured a small but deadly scout of an unknown civilization. Its pilot was killed, but without a doubt it was a human being. Studying the memory of the scout showed that another civilization had transferred its planetary system to a region of space close by, perhaps escaping a cataclysm. Strangely enough, they shaped their continents to resemble a perfect circle and square — so Andrey Khrumov called them Geometers.', 4, NULL, 'thestarsarecoldtoys.jpg'),
(6, 'A Clash of Kings', 'George Martin', 1998, 'A comet the color of blood and flame cuts across the sky. And from the ancient citadel of Dragonstone to the forbidding shores of Winterfell, chaos reigns. Six factions struggle for control of a divided land and the Iron Throne of the Seven Kingdoms, preparing to stake their claims through tempest, turmoil, and war. It is a tale in which brother plots against brother and the dead rise to walk in the night. Here a princess masquerades as an orphan boy; a knight of the mind prepares a poison for a treacherous sorceress; and wild men descend from the Mountains of the Moon to ravage the countryside. Against a backdrop of incest and fratricide, alchemy and murder, victory may go to the men and women possessed of the coldest steel...and the coldest hearts. For when kings clash, the whole land trembles.', 1, 0, 'clashofkings.jpg'),
(7, 'Empire of the Ants', 'Bernard Werber', 1991, 'The plot begins as two stories that take place in parallel: one in the world of humans (in Paris), the other in the world of ants (in a Formica rufa colony in a park near Paris). The time is the early 21st century (the near future, relative to the time when Werber wrote the book). The human character receives a house and a provocative message as legacy from his recently deceased uncle. He begins to investigate his uncle''s life and mysterious activities, and decides to descend into the cellar of the house but does not return. His family and other people follow, and disappear. The ant character is a male whose foraging expedition gets destroyed in one strike, by a mysterious force that comes from above. He suspects that a colony of another ant species has attacked them with a secret weapon, and attempts to meet with the queen and to rally other ants to investigate the disaster. However, he attracts the attention of a secret group of ants within the same colony that appear to want to conceal this information. As the plot unfolds, the humans and the ants encounter new mysteries and participate in challenging events, including a war between different ant species.', 2, NULL, 'empireoftheants.jpg'),
(8, 'A Storm of Swords', 'George Martin', 2000, 'Of the five contenders for power, one is dead, another in disfavor, and still the wars rage as violently as ever, as alliances are made and broken. Joffrey, of House Lannister, sits on the Iron Throne, the uneasy ruler of the land of the Seven Kingdoms. His most bitter rival, Lord Stannis, stands defeated and disgraced, the victim of the jealous sorceress who holds him in her evil thrall. But young Robb, of House Stark, still rules the North from the fortress of Riverrun. Robb plots against his despised Lannister enemies, even as they hold his sister hostage at King’s Landing, the seat of the Iron Throne. Meanwhile, making her way across a blood-drenched continent is the exiled queen, Daenerys, mistress of the only three dragons still left in the world. . . .', 1, 0, 'stormofswords.jpg'),
(9, 'Anna Karenina', 'Leo Tolstoy', 1877, 'One of the greatest novels ever written, “Anna Karenina” follows the self-destructive path of a beautiful, popular, and sensual Russian aristocrat. The lovely Anna seems set in a respectable marriage with the powerful statesman Karenin, yet their lack of passion breeds the discontent she fully faces upon meeting the elegant and affluent officer Count Vronsky. Soon convinced that allowing herself to deeply love this man will enable her to find the meaning and truth of her life, Anna defies the conventions of Russian society and leaves her husband and children for her lover. Tolstoy juxtaposes this ill-fated couple with the melancholy Levin and his new wife Kitty. Levin is also searching for the fulfillment and happiness in his life, and he ultimately finds a happiness that Anna’s love does not. A portrait of marriage and infidelity in imperial Russia, “Anna Karenina” explores love, life, and the depths of the human soul in a tale as illuminating as it is tragic. This edition is printed on premium acid-free paper, follows the translation of Constance Garnett, and includes an introduction by Nathan Haskell Dole.', 2, NULL, 'annakarenina.jpg'),
(10, 'The Lost World', 'Arthur Conan Doyle', 1912, 'The restless, questing intellect of Sir Arthur Conan Doyle spurred him far beyond the ingenious puzzles he constructed for Sherlock Holmes. In The Lost World, Doyle, a devotee of the occult and fantastic tales of adventure and discovery, introduces his readers to Professor Challenger, an eccentric paleontologist, on his suspense-filled search for prehistoric creatures in the wilds of the Amazon. Professor Challenger''s doughty troupe includes a skeptical colleague, Professor Summerlee; the cool-headed, plucky sportsman Lord John Roxton; and the narrator, the intrepid reporter Edward Malone. When their bridge to civilization collapses, the explorers find themselves marooned among dinosaurs and savage ape-people.\r\nOriginally published in 1912, this imaginative fantasy unfolds with humor and good-natured satirical eye for pedantry. Fans of Arthur Conan Doyle will delight in this rare gem, as will dinosaur fanciers and adventure story aficionados.', 4, 0, 'thelostworld.jpg'),
(11, '20,000 Leagues Under the Sea', 'Jules Verne', 1870, 'Professor Aronnax, his faithful servant, Conseil, and the Canadian harpooner, Ned Land, begin an extremely hazardous voyage to rid the seas of a little-known and terrifying sea monster. However, the "monster" turns out to be a giant submarine, commanded by the mysterious Captain Nemo, by whom they are soon held captive.\r\n\r\nSo begins not only one of the great adventure classics by Jules Verne, the ''Father of Science Fiction'', but also a truly fantastic voyage from the lost city of Atlantis to the South Pole.', 4, NULL, '20000leaguesunderthesea.jpg'),
(12, 'Journey to the Center of the Earth', 'Jules Verne', 1864, '"The reason Verne is still read by millions today is simply that he was one of the best storytellers who ever lived." — Arthur C. Clarke\r\nAn adventurous geology professor chances upon a manuscript in which a 16th-century explorer claims to have found a route to the earth''s core. Professor Lidenbrock can''t resist the opportunity to investigate, and with his nephew Axel, he sets off across Iceland in the company of Hans Bjelke, a native guide. The expedition descends into an extinct volcano toward a sunless sea, where they encounter a subterranean world of luminous rocks, antediluvian forests, and fantastic marine life — a living past that holds the secrets to the origins of human existence.', 4, 0, 'journeytothecenteroftheearth.jpg');

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

-- --------------------------------------------------------

--
-- Структура таблицы `themes`
--

CREATE TABLE `themes` (
  `id` int(11) NOT NULL,
  `name_theme` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Дамп данных таблицы `themes`
--

INSERT INTO `themes` (`id`, `name_theme`) VALUES
(1, 'fantasy'),
(2, 'novel'),
(3, 'popular-science'),
(4, 'fantastic');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
