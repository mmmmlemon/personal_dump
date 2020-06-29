
import React, {Component} from 'react';
import {StatusBar} from 'react-native';
import Icon from 'react-native-vector-icons/Ionicons';

export default class CustStatusBar extends React.Component {

  render() {
      return (
        <StatusBar
        backgroundColor="#4C65DC"
        barStyle="light-content"
        />
      );
    }
  }