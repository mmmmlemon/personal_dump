<?php

namespace App\Http\Controllers;
use Illuminate\Http\Request;
use App\Http\Resources\SteamUserCollection;
use App\SteamUser;
use App\Settings;

class SteamUserController extends Controller
{

    public function getStats($id)
    {
        //получаем пользователя стим из базы данных по ID
        $steamUser = SteamUser::find($id);

        //получаем ключ API из настроек
        $api_key = Settings::all()[0]->api_key;

        //общая информация о игроке
       $url = "http://api.steampowered.com/ISteamUser/GetPlayerSummaries/v0002/?key=" . $api_key . "&steamids=" . $steamUser->steam_id;

       //список игр
       $url_games = "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=" . $api_key . "&steamid=" . $steamUser->steam_id . "&format=json";

       $json = json_decode(file_get_contents($url), true)['response']['players'][0];
       $json_games = json_decode(file_get_contents($url_games), true)['response'];

       //конвертируем unix time в нормальный формат даты
       $json['timecreated'] = gmdate('d-m-Y', $json['timecreated']);
       $json['lastlogoff'] = gmdate('d-m-Y', $json['lastlogoff']);
    
       $json_array = array('user_info' => $json, 'user_games_count' => $json_games['game_count']);


       return response()->json($json_array);
        
    }


    public function store(Request $request)
    {
     
        $steamUser = new SteamUser([
            'username' => $request->get('username'),
            'steam_id' => $request->get('steam_id')
        ]);

        $steamUser->save();

        return response()->json('success');
    }

    public function index()
    {
        return new SteamUserCollection(SteamUser::all());

    }

    public function edit($id)
    {
        $steamUser = SteamUser::find($id);
        return response()->json($steamUser);
    }

    public function update($id, Request $request)
    {

        echo "<script> console.warn('IM HERE')</script>";
        $steamUser = SteamUser::find($id);
        $steamUser->update($request->all());

        return response()->json('successfully updated');
    }

    public function delete($id)
    {
        $steamUser = SteamUser::find($id);

        $steamUser->delete();

        return response()->json('successfully deleted');
    }
}
