<?php

use Illuminate\Http\Request;

/*
|--------------------------------------------------------------------------
| API Routes
|--------------------------------------------------------------------------
|
| Here is where you can register API routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| is assigned the "api" middleware group. Enjoy building your API!
|
*/

Route::middleware('auth:api')->get('/user', function (Request $request) {
    return $request->user();
});

Route::post('/steamuser/create', 'SteamUserController@store');
Route::get('/steamuser/edit/{id}', 'SteamUserController@edit');
Route::post('/steamuser/update/{id}', 'SteamUserController@update');
Route::delete('/steamuser/delete/{id}','SteamUserController@delete');
Route::get('/steamusers', 'SteamUserController@index');
Route::get('/steamuser/stats/{id}', 'SteamUserController@getStats');
