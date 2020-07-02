'use strict';

var React = require('react-native');

var {
  StyleSheet,
} = React;

module.exports = StyleSheet.create({
    container: {
      flex: 1,
    },
    content: {
      margin: 20
    },
    header:{
      margin: 10,
      backgroundColor: "#305075"
    },
    title: {
      marginLeft:20,
      fontSize:25
    },
    subtitle: {
      marginLeft: 20,
    },
    result: {
        fontSize: 40,
        marginTop: 20,
        textAlign: 'center'
    },
    calculateButton:{
      backgroundColor: "#307558"
    },
    clearButton: {
      backgroundColor: "#753c30"
    }
  });
