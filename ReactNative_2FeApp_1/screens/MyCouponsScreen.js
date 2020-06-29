import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View} from 'react-native';
import Icon from 'react-native-vector-icons/FontAwesome';

export default class MyCouponsScreen extends React.Component {
   
  static navigationOptions = {
    tabBarLabel: "Мои купоны",
    tabBarIcon: ({ tintColor }) => (<Icon name="user" style  = {{fontSize:26}}color={ tintColor } />)
  }
  
  render() {
      return (
        <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
          <Text>Мои Купоны\Профиль пользователя</Text>
        </View>
      );
    }
  }