<?php
class User {
	public $name;
	public $age;
	public $city;
    public $albums;
    
    public function __construct($name) {
        $this->name = $name;
        $this->albums = array();
    }
};

class Album {
	public $name;
	public $singer;
	public $genre;
    public $trackCount;
};

$n = readline();
$m = null;

$users = array();
list($_, $_, $userName) = explode(" ", readline());

while ($n--) {
    $user = new User($userName);
    list($_, $user->age) = explode(" ", trim(readline()));
    list($_, $user->city) = explode(" ", trim(readline()));
    
    $line = readline();
    while ($line = readline()) {
        if ($line[0] != " ")
            break;
        list($_, $album) = explode(" ", trim($line));
        array_push($user->albums, $album);
    }

    array_push($users, $user);
    if ($n) {
        list($_, $_, $userName) = explode(" ", $line);
        continue;
    }
    $m = $line;
}

$albums = array();
while ($m--) {
    $album = new Album;
    list($_, $_, $album->name) = explode(" ", readline());
    list($_, $album->singer) = explode(" ", trim(readline()));
    list($_, $album->genre) = explode(" ", trim(readline()));
    list($_, $album->trackCount) = explode(" ", trim(readline()));
    array_push($albums, $album);
}

function findAlbum($name) {
    global $albums;
    foreach ($albums as $album)
        if ($album->name == $name)
			return $album;
}

function userQuery($userKey, $userValue, $key, $value) {
    $res = 0;
    global $users;
    foreach ($users as $user)
        if ($user->{$userKey} == $userValue)
            foreach ($user->albums as $albumName) {
                $album = findAlbum($albumName);
                if ($album->{$key} == $value)
                    $res += $album->trackCount;
            }
    return $res;
}

$q = readline();
while ($q--) {
    list($type, $s1, $s2) = explode(" ", readline());
    
    $res = 0;
    switch ($type) {
        case 1:
            $res = userQuery("name", $s1, "singer", $s2);
            break;
        case 2:
            $res = userQuery("name", $s1, "genre", $s2);
            break;
        case 3:
            $res = userQuery("age", $s1, "singer", $s2);
            break;
        case 4:
            $res = userQuery("age", $s1, "genre", $s2);
            break;
        case 5:
            $res = userQuery("city", $s1, "singer", $s2);
            break;
        case 6:
            $res = userQuery("city", $s1, "genre", $s2);
            break;
    }
    echo "{$res}\n";
}
?>
