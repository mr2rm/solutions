<?php
class User {
	public $name;
	public $age;
	public $city;
    public $albums;
    
    public function __construct($name) {
        $this->name = $name;
        $this->albums = [];
    }
};

class Album {
	public $name;
	public $singer;
	public $genre;
    public $trackCount;
};

$n = readline();
list($_, $_, $userName) = explode(" ", readline());

$m = null;
$users = [];
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

$albums = [];
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

function query($userKey, $userValue, $albumKey, $albumValue) {
    $res = 0;
    global $users;
    foreach ($users as $user)
        if ($user->{$userKey} == $userValue)
            foreach ($user->albums as $albumName) {
                $album = findAlbum($albumName);
                if ($album->{$albumKey} == $albumValue)
                    $res += $album->trackCount;
            }
    return $res;
}

$q = readline();
$cmd = [
    ["name", "singer"],
    ["name", "genre"],
    ["age", "singer"],
    ["age", "genre"],
    ["city", "singer"],
    ["city", "genre"],
];

while ($q--) {
    list($type, $userValue, $albumValue) = explode(" ", readline());
    list($userKey, $albumKey) = $cmd[$type - 1];
    $res = query($userKey, $userValue, $albumKey, $albumValue);
    echo "{$res}\n";
}
?>
