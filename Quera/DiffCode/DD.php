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
[$_, $_, $userName] = explode(" ", readline());

$m = null;
$users = [];
while ($n--) {
    $user = new User($userName);
    [$_, $user->age] = explode(" ", trim(readline()));
    [$_, $user->city] = explode(" ", trim(readline()));
    
    $line = readline();
    while ($line = readline()) {
        if ($line[0] != " ")
            break;
        [$_, $album] = explode(" ", trim($line));
        array_push($user->albums, $album);
    }

    array_push($users, $user);
    if ($n) {
        [$_, $_, $userName] = explode(" ", $line);
        continue;
    }
    $m = $line;
}

$albums = [];
while ($m--) {
    $album = new Album;
    [$_, $_, $album->name] = explode(" ", readline());
    [$_, $album->singer] = explode(" ", trim(readline()));
    [$_, $album->genre] = explode(" ", trim(readline()));
    [$_, $album->trackCount] = explode(" ", trim(readline()));
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
    [$type, $userValue, $albumValue] = explode(" ", readline());
    [$userKey, $albumKey] = $cmd[$type - 1];
    $res = query($userKey, $userValue, $albumKey, $albumValue);
    echo "{$res}\n";
}
?>
