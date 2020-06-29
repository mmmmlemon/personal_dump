//импорты библиотек
import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View} from 'react-native';
import { createBottomTabNavigator, createAppContainer } from 'react-navigation';

//импорты других экранов
import CouponsScreen from './screens/CouponsScreen'
import FeaturedScreen from './screens/FeaturedScreen'
import NewsScreen from './screens/NewsScreen'
import MyCouponsScreen from './screens/MyCouponsScreen'


export default class MainScreen extends React.Component {
  render() {
    return (
        <AppContainer />
    );
  }
}

const TabNavigator = createBottomTabNavigator({
  Coupons: {screen: CouponsScreen},
  Featured: FeaturedScreen,
  News: NewsScreen,
  MyCoupons: MyCouponsScreen,
},{
  tabBarOptions: {
    activeTintColor: "#4C65DC",
    style: {
      backgroundColor: 'white',
   }
  }
});

const AppContainer = createAppContainer(TabNavigator);