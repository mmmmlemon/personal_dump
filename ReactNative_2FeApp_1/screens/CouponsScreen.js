import React, {Component} from 'react';
import {Platform, StyleSheet, Text, View, StatusBar, Image} from 'react-native';
import {Container, Header, Tabs, Tab, ScrollableTab, Card, CardItem,Left,Right,Body, Button,
Content} from 'native-base'
import Icon from 'react-native-vector-icons/FontAwesome';

import CustStatusBar from '../customComponents/StatusBar'
import CouponCard from '../customComponents/CouponCard'

var styles = require('../styleSheet');



//json с купонами (пока что с локального файла)
var json = require('../json/coupons.json');
var allJson = require('../json/all.json');




//класс экрана купонов
export default class CouponsScreen extends React.Component {

  //настройки для таб бара (заголовок и иконка)
 static navigationOptions = {
    tabBarLabel: "Купоны",
    tabBarIcon: ({ tintColor }) => (<Icon name="tags" style  = {{fontSize:26}}color={ tintColor }  />)
  }

  constructor(props) {
    super(props);
    this.state = {tabs:[], all: []};
  }

    //когда компонент "встроится" в верстку, то выполнится этот код
    componentWillMount(){
            //список всех купонов который будет записан в стейт all
            var allList = [];
            //список всех табов категорий
            var tabsList = [];

      //сначала создаем список со всеми купонами и выводим его в UI 
          for(let coupon of allJson){
              allList.push(<CouponCard key = {coupon.id} title = {coupon.title} 
              price = {coupon.price} endDate = {coupon.endDate} endsIn = {coupon.endsIn}
              purchases = {coupon.purchases} image = {coupon.image}/>)
          }

          //выводим все категории в виде табов
          for(let category of json){

            var couponsList = [];

            for (coupon of category.coupons){
              couponsList.push(<CouponCard key = {coupon.id} title = {coupon.title} 
                price = {coupon.price} endDate = {coupon.endDate} endsIn = {coupon.endsIn}
                purchases = {coupon.purchases} image = {coupon.image}/>)
            }

            tabsList.push(<Tab key = {category.id} activeTabStyle = {styles.tabActiveBack} 
              activeTextStyle = {styles.tabActiveText} 
              tabStyle = {{backgroundColor:'white'}}
              heading={category.name} >
              <Content>
                 {couponsList}
              </Content>               
          </Tab>)
          }

          //обновляем стейт со всеми купонами
          this.setState(this.state.all = allList);
          //обновляем стейт со списоком табов
          this.setState(this.state.tabs = tabsList);

      }

    render() {
      return (
        
        <Container>
      
   
          <Header style = {{height:23, backgroundColor: 'white'}}hasTabs>
            <CustStatusBar />
          </Header>

            <Tabs style = {{backgroundColor: 'white'}}
                  tabBarUnderlineStyle = {styles.tabsUnderline}
                  renderTabBar={()=> <ScrollableTab 
                    tabsContainerStyle={{ backgroundColor: 'white' }}/>}
                    prerenderingSiblingsNumber={0}>

              {/*Список категорий купонов в виде табов */}

                {/*ВСЕ КУПОНЫ*/}
                <Tab activeTabStyle = {styles.tabActiveBack} 
                  activeTextStyle = {styles.tabActiveText} 
                  tabStyle = {{backgroundColor:'white'}}
                  heading="Все купоны" >
                  <Content>
                      {this.state.all}
                  </Content>               
              </Tab>
                {this.state.tabs}
            </Tabs>

      </Container>

      );
    }
  }