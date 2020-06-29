import React, {Component} from 'react';
import { Text, View,  Image} from 'react-native';
import { Card, CardItem,Left,Right, Button} from 'native-base'
import Icon from 'react-native-vector-icons/FontAwesome';
import {FadeIn, FavPressed} from '../anim/poseAnim'

var styles = require('../styleSheet');

//класс карточки купона
export default class CouponCard extends React.Component{
    constructor(props){
      super(props);
      this.state = {isVisible: false, isPressed: false, favColor: 'white'};
    }

    componentDidMount() {
      this.setState({ isVisible: !this.state.isVisible});
    }

    favPressed = () =>{

      this.setState({ isPressed: !this.state.isPressed});

      if(this.state.favColor == 'white'){
      this.setState({favColor: 'red'});}
      else{
        this.setState({favColor: 'white'});}


    }

    render(){
      return(
        <FadeIn pose={this.state.isVisible ? 'visible' : 'hidden'}>
        <Card transparent style = {{marginBottom:12}}>
          <CardItem cardBody>
            {/*КАРТИНКА */}
            <Image source={{uri: this.props.image}} 
                  style={styles.couponCardImage}/>
            {/*ОВЕРЛЕЙ СО СКИДКОЙ*/}
            <View style = {styles.discountOverlay}>
              <Text style = {styles.discountOverlayText}>
                -{this.props.price}%
              </Text>
            </View>

            {/*ОВЕРЛЕЙ С ТАЙМЕРОМ ОКОНЧАНИЯ*/}
            <View style = {styles.timerOverlay}>
              <Text style = {styles.timerOverlayTextTitle}>
                Закончится через
              </Text>
              <Text style = {styles.timerOverlayTextTime}>
                {this.props.endsIn}
              </Text>
            </View>

            {/*КНОПКА ДОБАВИТЬ В ИЗБРАННОЕ */}
            <FavPressed pose={this.state.isPressed ? 'faved' : 'unfaved'} style ={styles.favoriteButtonView}>
            <Button transparent style = {styles.favoriteButton} onPress = {()=>this.favPressed()}>
            <Icon name='heart' style = {{fontSize: 31, color: this.state.favColor}}/>
          </Button>
              </FavPressed>
          </CardItem>


          <CardItem style ={{flexDirection:'column',  alignItems: 'stretch'}}>
            {/*НАЗВАНИЕ КУПОНА*/}
            <Text style = {styles.cardCouponTitle}>{this.props.title}</Text>
            {/*ЦЕНА */}
            <Text style = {styles.cardCouponPrice}>{this.props.price} ₽</Text>
  
            <View style = {{flexDirection:'row',marginTop: 7}}>
              <Left style = {{flex:2, flexDirection:'row', alignItems:'center'}}>
                {/*ДАТА ОКОНЧАНИЯ */}
                <Icon name="calendar" style  = {{fontSize:16, marginRight:5, color: '#c67731'}}/>
                <Text style = {{fontSize: 13}}>Заканчивается: {this.props.endDate}</Text>
              </Left>
              <Right style = {{flex:1, flexDirection:'row', alignItems:'center'}}>
                {/*КОЛИЧЕСТВО КУПИВШИХ */}
                <Icon name="credit-card" style  = {{fontSize:16, marginRight:5, color: '#4f34db'}} />
                <Text style = {{fontSize: 13}}>Купили: {this.props.purchases}</Text>
              </Right>
            </View>
          </CardItem> 

      </Card>
      </FadeIn>
      );
    }
  }
