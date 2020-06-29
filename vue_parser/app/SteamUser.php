<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class SteamUser extends Model
{
    protected $fillable = ['username', 'steam_id'];
}


