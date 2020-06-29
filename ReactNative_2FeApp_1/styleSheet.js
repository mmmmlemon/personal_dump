'use strict';

var React = require('react-native');

var {
  StyleSheet,
} = React;

module.exports = StyleSheet.create({

purpleText: {
    color: "#4C65DC",
},


/////ТАБЫ////////
//
tabActiveBack:{
  backgroundColor: 'white',
},

//текст у активного таба
tabActiveText:{
  color: "#4C65DC",
},

//дефолтный стиль у таба
tabDefault:{
  backgroundColor: 'white',
  color: 'grey',
},

//полоска на табах
tabsUnderline:{
  backgroundColor: "#4C65DC"
},
/////////////////

////////КУПОНЫ///////
//оверлей со скидкой на купоне
couponCardImage:{
  height: 200, 
  width: null, 
  flex: 1, 
  borderRadius: 10
},

discountOverlay:{
  position:'absolute', 
  top: 0, 
  left: 0, 
  backgroundColor: '#e03838',               
  width: null, borderTopLeftRadius:10, borderBottomRightRadius:10
},

discountOverlayText: {
  fontSize:33, 
  color: 'white', 
  marginLeft:7, 
  marginRight: 5
},

timerOverlay:{
  flexDirection:'column',
  position:'absolute', 
  top: 0, 
  right: 0, 
  backgroundColor: 'rgba(0,0,0,0.4)', 
  width: null, 
  borderBottomLeftRadius:10, 
  borderTopRightRadius:10
},

timerOverlayTextTitle:{
  fontSize:13, 
  color: 'white', 
  marginRight:9, 
  alignSelf:'flex-end'
},

timerOverlayTextTime: {
  fontSize:16, 
  color: 'white', 
  marginRight:9, 
  marginLeft:5,
  alignSelf:'flex-end'
},

cardCouponTitle: {
  textAlign:'left',
  flex:1,
  fontSize: 18,
  textAlign:'left'
},

cardCouponPrice: {
  flex:1,
  fontSize: 18,
  textAlign:'left'
},

favoriteButtonView:{
  position:'absolute', 
  bottom: 5, 
  right: 10, 

},

favoriteButton:{
  width: 50,
  height: 50,
  justifyContent: 'center',
  borderRadius: 100,
  backgroundColor: 'rgba(0,0,0,0.4)'
},



});