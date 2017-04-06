import Data.Char
 
data KeyCode = Key Char| CapsLock | Shift Charderiving(Eq,Show)
 
getSym :: KeyCode ->MaybeChar
getSym (Key a)= Just a
getSym (Shift a)= Just a
getSym CapsLock = Nothing
 
getAlNum ::[KeyCode]->[KeyCode]
getAlNum []=[]
getAlNum (k:ks)=
case k of
 Key a -> k : getAlNum ks
_-> getAlNum ks
 
getRaw ::[KeyCode]->[Char]
getRaw []=[]
getRaw (k:ks)=
case getSym k of
        Just sym -> sym : getRaw ks
        Nothing -> getRaw ks
 
isCapsLocked  ::[KeyCode]->Bool
isCapsLocked list = isCapsLocked' list False
    where
        isCapsLocked'[] cl = cl
        isCapsLocked' (k:ks) cl = isCapsLocked' ks cl'
            where
                cl'=case k of
                    CapsLock ->not cl
_-> cl
 
 
changeCase ::Bool->Char->Char
changeCase False c = c
changeCase True c =if isUpper c then toLower c else toUpper c
 
getString ::[KeyCode]->String
getString codes = getString' codes False
    where
        getString'::[KeyCode]->Bool->String
        getString' [] _ = ""
        getString'(k:ks) cl =
case k of
                Key a -> changeCase cl a : getString' ks cl
                Shift a -> changeCase cl (changeCase True a) : getString' ks cl
                CapsLock -> getString' ks (not cl)
