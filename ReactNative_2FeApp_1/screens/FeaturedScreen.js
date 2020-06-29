import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View} from 'react-native';
import Icon from 'react-native-vector-icons/FontAwesome';

export default class FeaturedScreen extends React.Component {
   
  static navigationOptions = {
    tabBarLabel: "Избранное",
    tabBarIcon: ({ tintColor }) => (<Icon name="heart" style  = {{fontSize:26}}color={ tintColor }  />)
  }
  
  render() {
      return (
        <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
          <Text>Продвигаемое</Text>
        </View>
      );
    }
  }